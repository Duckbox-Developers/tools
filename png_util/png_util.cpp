#include <linux/fb.h>
#include "png_util.h"

#if BOXMODEL_DM8000
const char* device_file_name = "/dev/oled0";
#else
const char* device_file_name = "/dev/lcd2";
#endif

static int x, y;
static int width, height;

static png_byte color_type;
static png_byte bit_depth;

static png_structp png_ptr;
static png_infop info_ptr;
static int number_of_passes;
static png_bytep * row_pointers = 0;
static png_bytep row_pointers_bit_shift = 0;
static int row_byte_len = 0;

#define FB_WIDTH_STD 400
#define FB_HEIGHT_STD 240
#define FB_BPP 16

#ifndef FBIO_BLIT
#define FBIO_SET_MANUAL_BLIT _IOW('F', 0x21, __u8)
#define FBIO_BLIT 0x22
#endif

struct fb_var_screeninfo g_screeninfo_var;

static int init_fb(const char* g_fbDevice)
{
	int g_fbFd = open(g_fbDevice, O_RDWR);
	if (ioctl(g_fbFd, FBIO_BLIT) < 0)
		perror("FBIO_BLIT");
	unsigned char tmp = 1;
	if (ioctl(g_fbFd, FBIO_SET_MANUAL_BLIT, &tmp)<0)
		perror("FBIO_SET_MANUAL_BLIT (on)");
	tmp = 0;
	if (ioctl(g_fbFd, FBIO_SET_MANUAL_BLIT, &tmp)<0)
		perror("FBIO_SET_MANUAL_BLIT (off)");

	g_screeninfo_var.xres_virtual = g_screeninfo_var.xres = FB_WIDTH_STD;
	g_screeninfo_var.yres_virtual = g_screeninfo_var.yres = FB_HEIGHT_STD;

//	printf("OSD-RES: %i x %i\n", g_screeninfo_var.xres_virtual, g_screeninfo_var.yres_virtual);

	g_screeninfo_var.bits_per_pixel = FB_BPP;
	g_screeninfo_var.xoffset = g_screeninfo_var.yoffset = 0;
	g_screeninfo_var.height = 0;
	g_screeninfo_var.width = 0;

	if (ioctl(g_fbFd, FBIOPUT_VSCREENINFO, &g_screeninfo_var) < 0)
		perror("Error: Cannot set variable information!");

	if (g_fbFd >= 0)
	{
		close(g_fbFd);
		g_fbFd = -1;
	} else
		perror("Error: Framebuffer not available!\n");

	return 0;
}

static int read_png_file(char* file_name)
{
	/* 8 is the maximum size that can be checked */
	char header[8] = {0,};

	/* open file and test for it being a png */
	FILE *fp = fopen(file_name, "rb");
	if (!fp)
	{
		fprintf(stderr, "[read_png_file] File %s could not be opened for reading.\n", file_name);
		return 0;
	}

	fread(header, 1, 8, fp);
	if (png_sig_cmp((png_byte*)header, 0, 8))
	{
		fclose(fp);
		fprintf(stderr, "[read_png_file] File %s is not recognized as a PNG file.\n", file_name);
		return 0;
	}

	/* initialize stuff */
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	if (!png_ptr) 
	{
		fclose(fp);
		fprintf(stderr, "[read_png_file] png_create_read_struct failed.\n");
		return 0;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		fclose(fp);
		fprintf(stderr, "[read_png_file] png_create_info_struct failed.\n");
		return 0;
	}

	if (setjmp(png_jmpbuf(png_ptr)))
	{
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
		fprintf(stderr, "[read_png_file] Error during init_io.\n");
		return 0;
	}

	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, 8);

	png_read_info(png_ptr, info_ptr);

	width = png_get_image_width(png_ptr, info_ptr);
	height = png_get_image_height(png_ptr, info_ptr);
	if (width != 400 || height != 240)
	{
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
		fprintf(stderr, "[read_png_file] Error invalid image size.\n");
		return 0;
	}
	color_type = png_get_color_type(png_ptr, info_ptr);
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);

	number_of_passes = png_set_interlace_handling(png_ptr);
	png_read_update_info(png_ptr, info_ptr);

        /* read file */
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
		fprintf(stderr, "[read_png_file] Error during read_image.\n");
		return 0;
	}

	if(row_pointers == 0)
	{
		row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
		row_byte_len = png_get_rowbytes(png_ptr,info_ptr);
		for (y=0; y<height; y++)
		{
			row_pointers[y] = (png_byte*) malloc(row_byte_len);
		}
		row_pointers_bit_shift = (unsigned char*) malloc(sizeof(unsigned char) * height * width * 2);
	}

	png_read_image(png_ptr, row_pointers);
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(fp);
	return 1;
}

PNGUtil *PNGUtil::instance = 0;

PNGUtil::PNGUtil() 
{
	instance = this;
	device_fd = -1;
}

PNGUtil::~PNGUtil()
{
	disconnect();
}

PNGUtil *PNGUtil::getInstance()
{
	return instance;
}

int PNGUtil::connect()
{
	device_fd = open(device_file_name, O_RDWR);
	if(device_fd < 0)
		return 0;
	return 1;
}

void PNGUtil::disconnect() 
{
	if(device_fd >= 0)
	{
		close(device_fd);
		device_fd = -1;
	}
}

int PNGUtil::send(char* png_file_name) 
{
	if(device_fd < 0) 
	{
		fprintf(stderr, "Device %s could not be opened.\n", device_file_name);
		return 0;
	}

	if(!read_png_file(png_file_name))
	{
		return 0;
	}

	int i,j;
	int row_pointers_ptr = 0;
	int row_pointers_2_ptr = 0;
	
	for(i=0;i<height;i++)
	{
		for(j=0;j<row_byte_len;j+=3)
		{
			row_pointers_bit_shift[row_pointers_2_ptr]=(row_pointers[i][j]&248)|(row_pointers[i][j+1]>>5);
			row_pointers_bit_shift[row_pointers_2_ptr+1]=((row_pointers[i][j+1]&28)<<3)|(row_pointers[i][j+2]>>3);
			row_pointers_2_ptr += 2;
		}
	}

	int w=-1;
	w = write(device_fd, row_pointers_bit_shift, height * width * 2);
//	printf("write ret : %d\n", w);
//	w = ioctl(device_fd, 0);
//	printf("write to %s : %d\n", device_file_name, w);
	return 1;
}

int main (int argc, char* argv[]) {
	if (argc < 2) {
		printf("png_util - for 400x240 LCD (DM8000, VUDUO2)\n\n");
		printf("Syntax:  png_util <png file or initonly> (%s)\n", device_file_name);
		printf("Example: png_util initonly\n");
		printf("Example: png_util /path/file.png\n");
		printf("Example: png_util /path/file.png %s\n\n", device_file_name);
		return 0;
	}

	if (argv[2])
		device_file_name = argv[2];

	if (!strncmp(argv[1], "initonly", 8))
	{
		int lcd_fd = open(device_file_name, O_WRONLY);
		if (lcd_fd)
		{
			ioctl(lcd_fd, 0x10, 128); // brightness 0..255
			close(lcd_fd);
		}
		init_fb(device_file_name);
		sleep(1);
		return 1;
	}

	init_fb(device_file_name);
	PNGUtil anzeige = PNGUtil();
	anzeige.getInstance()->connect();
	int ret = anzeige.getInstance()->send(argv[1]);
	anzeige.getInstance()->disconnect();
	return ret;
}
