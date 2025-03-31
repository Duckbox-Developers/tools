/*
 * lcd for DM8000/DM7020/DM7080
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
*/

#include "lcd.h"
#include "lcd_font.h"

static unsigned char raw[132][64];
static unsigned char rawb[132][64];
static unsigned char lcd[LCD_ROWS][LCD_COLS];
static int fd = -1;
static unsigned char iconBasePath[512];

void LCD_Read(void)
{
	int x,y,z;
	char tmp2;

	memset(raw,0,132*64);
	read(fd, &lcd, 120*64/8);
	for(x=0;x < LCD_COLS;x++)
	{   
		for(y=0;y < LCD_ROWS; y++)
		{
			tmp2 = lcd[y][x];
			for(z=0;z <= 7;z++)
			{
				if(tmp2 & (1<<z))
					raw[x][y * 8 + z] = 1;
			}
		}
	}
}

int LCD_Init(void)
{
	//open device
	if((fd = open("/dev/dbox/lcd0",O_RDWR)) < 0)
	{
		perror("LCD (/dev/dbox/lcd0)");
		return -1;
	}

	LCD_Read();
	LCD_brightness(5);
	LCD_setIconBasePath("/usr/share/tuxbox/lcd/icons/");
	return 0;
}

void LCD_Clear(void)
{
	memcpy(raw,rawb,132*64);
	LCD_update();
}

int LCD_Close(void)
{
	if(fd>=0)
	{
		close(fd);
		fd=-1;
	}
	return 0;
}

int LCD_invalid_col (int x)
{
	if( x > LCD_COLS )
		return -1;
	if( x < 0 )
		return -1;
	return 0;
}

int LCD_invalid_row (int y)
{
	if( y > LCD_ROWS * 8 )
		return -1;
	if( y < 0)
		return -1;
	return 0;   
}

void LCD_convert_data ()
{
	int x,y,z;
	char tmp2;
	for(x=0;x < LCD_COLS;x++) {
		for(y=0;y < LCD_ROWS;y++) {
			tmp2 = 0;
			for(z=0;z <= 7;z++) {
				if(raw[x][y * 8 + z] == 1) {
					tmp2|=1<<z;
				}
			}
			lcd[y][x] = tmp2;
		}
	}
}

int LCD_brightness(int brightness)
{
	int value = 0;
	switch(brightness) {
		case 0:
			value = 0;
			break;
		case 1:
			value = 25;
			break;
		case 2:
			value = 51;
			break;
		case 3:
			value = 76;
			break;
		case 4:
			value = 102;
			break;
		case 5:
			value = 127;
			break;
		case 6:
			value = 153;
			break;
		case 7:
			value = 178;
			break;
		case 8:
			value = 204;
			break;
		case 9:
			value = 229;
			break;
		case 10:
			value = 255;
			break;
	}

	FILE *f = fopen("/proc/stb/lcd/oled_brightness", "w");
	if (f)
	{
		if (fprintf(f, "%d", value) == 0)
			printf("%s: write %s failed!! (%m)\n", __FUNCTION__, "/proc/stb/lcd/oled_brightness");
		fclose(f);
	}
	return 0;
}

void LCD_update()
{
	LCD_convert_data();
	write(fd, lcd, 120*64/8);
}

int LCD_sgn (int arg) 
{
	if(arg<0)
		return -1;
	if(arg>0)
		return 1;
	return 0;
}

void LCD_draw_point (int x,int y, int state)
{
	if(state == LCD_PIXEL_INV)
	{
		if(raw[x][y] == LCD_PIXEL_ON) 
			raw[x][y] = LCD_PIXEL_OFF;
		else
			raw[x][y] = LCD_PIXEL_ON;
	}
	else
		raw[x][y] = state;
}

/*
 * draw_line
 * 
 * args:
 * x1    StartCol
 * y1    StartRow
 * x2    EndCol
 * y1    EndRow
 * state LCD_PIXEL_OFF/LCD_PIXEL_ON/LCD_PIXEL_INV
 * 
 */
 
int abs(int val)
{
	return (val<0)?(-val):val;
}

void LCD_draw_line (int x1, int y1, int x2, int y2, int state)
{
	int dx,dy,sdx,sdy,px,py,dxabs,dyabs,i;
	float slope;

	if(LCD_invalid_col(x1) || LCD_invalid_col(x2))
		return;

	if(LCD_invalid_row(y1) || LCD_invalid_row(y2))
		return;

	dx=x2-x1;
	dy=y2-y1;
	dxabs=abs(dx);
	dyabs=abs(dy);
	sdx=LCD_sgn(dx);
	sdy=LCD_sgn(dy);
	if (dxabs>=dyabs) /* the line is more horizontal than vertical */ {
		slope=(float)dy / (float)dx;
		for(i=0;i!=dx;i+=sdx) {	     
			px=i+x1;
			py=(int)( slope*i+y1 );
			LCD_draw_point(px,py,state);
		}
	}
	else /* the line is more vertical than horizontal */ {
		slope=(float)dx / (float)dy;
		for(i=0;i!=dy;i+=sdy) {
			px=(int)(slope*i+x1);
			py=i+y1;
			LCD_draw_point(px,py,state);
		}
	}
}

void LCD_draw_fill_rect (int left,int top,int right,int bottom,int state) {
	int x,y;
	for(x = left + 1;x < right;x++) {  
		for(y = top + 1;y < bottom;y++) {
			LCD_draw_point(x,y,state);
		}
	}
}


void LCD_draw_rectangle (int left,int top, int right, int bottom, int linestate,int fillstate)
{
	if(LCD_invalid_col(left) || LCD_invalid_col(right))
		return;

	if(LCD_invalid_row(top) || LCD_invalid_row(bottom))
		return;

	LCD_draw_line(left,top,right,top,linestate);
	LCD_draw_line(left,top,left,bottom,linestate);
	LCD_draw_line(right,top,right,bottom,linestate);
	LCD_draw_line(left,bottom,right,bottom,linestate);
	LCD_draw_fill_rect(left,top,right,bottom,fillstate);
}

void LCD_draw_polygon(int num_vertices, int *vertices, int state) 
{
	//todo: mhh i think checking some coords. would be nice

	int i;
	for(i=0;i<num_vertices-1;i++) {
		LCD_draw_line(vertices[(i<<1)+0],
			vertices[(i<<1)+1],
			vertices[(i<<1)+2],
			vertices[(i<<1)+3],
			state);
	}

	LCD_draw_line(vertices[0],
		vertices[1],
		vertices[(num_vertices<<1)-2],
		vertices[(num_vertices<<1)-1],
		state);
}

void LCD_draw_char(int x, int y, char c)
{
	int ax,ay;
	unsigned char *data=&font[8*c];

	for (ay=0; ay<8; ay++)
		for (ax=0; ax<8; ax++)
			if ((!LCD_invalid_col(x+ax)) && (!LCD_invalid_row(y+ay)))
				LCD_draw_point(x+ax, y+ay, data[ay]&(1<<(7-ax)) ? PIXEL_ON:PIXEL_OFF);
}

void LCD_draw_string(int x, int y, char *string)
{
	while (*string)
	{
		LCD_draw_char(x, y, *string++);
		x+=8;
	}
}

void LCD_setIconBasePath(char *base)
{
	strcpy(iconBasePath, base);
}

void LCD_paintIcon(unsigned char *filename, int x, int y, int col)
{
	short width, height;
	unsigned char tr, iconfile[512];
	int count, count2;

	int fd;
	sprintf(iconfile,"%s%s",iconBasePath,filename);

	fd = open(iconfile, O_RDONLY );

	if (fd==-1)
	{
		printf("\nerror while loading icon: %s\n\n", iconfile);
		return;
	}

	read(fd, &width,  2);
	read(fd, &height, 2);
	read(fd, &tr, 1);

	width= ((width & 0xff00) >> 8) | ((width & 0x00ff) << 8);
	height=((height & 0xff00) >> 8) | ((height & 0x00ff) << 8);

	unsigned char pixbuf[200];
	for (count=0; count<height; count++)
	{
		read(fd, &pixbuf, width >> 1 );
		unsigned char *pixpos = (unsigned char*) &pixbuf;
		for (count2=0; count2<width >> 1; count2++)
		{
			unsigned char compressed = *pixpos;
			unsigned char pix1 = (compressed & 0xf0) >> 4;
			unsigned char pix2 = (compressed & 0x0f);

			if (pix1 == col)
				LCD_draw_point(x+(count2<<1),y+count, PIXEL_ON);
			else
				LCD_draw_point (x+(count2<<1),y+count, PIXEL_OFF);
			if (pix2 == col)
				LCD_draw_point(x+(count2<<1)+1,y+count, PIXEL_ON);
			else
				LCD_draw_point (x+(count2<<1)+1,y+count, PIXEL_OFF);
			pixpos++;
		}
	}

	close(fd);
}

typedef struct
{
	char *arg;
	char *arg_long;
	char *arg_description;
} tArgs;

tArgs vArgs[] =
{
	{ "-b  ",  " --setBrightness			", "Args: brightness\n\tSet lcd brightness" },
	{ "-c  ",  " --clear				", "Args: No argumens\n\tClear lcd display" },
	{ "-tu ",  " --setTextUp			", "Args: text\n\tSet text to lcd in up" },
	{ "-tc ",  " --setTextCenter			", "Args: text\n\tSet text to lcd in center" },
	{ "-td ",  " --setTextDown			", "Args: text\n\tSet text to lcd in down" },
	{ NULL, NULL, NULL }
};

void usage(char *prg, char *cmd)
{
	int i;
	/* or printout a default usage */
	fprintf(stderr, "LCD control tool, version 1.00 (DM8000/DM7020/DM7080)\n");
	fprintf(stderr, "General usage:\n\n");
	fprintf(stderr, "%s argument [optarg1] [optarg2]\n", prg);

	for (i = 0; ; i++)
	{
		if (vArgs[i].arg == NULL)
			break;
		if ((cmd == NULL) || (strcmp(cmd, vArgs[i].arg) == 0) || (strstr(vArgs[i].arg_long, cmd) != NULL))
			fprintf(stderr, "%s %s %s\n", vArgs[i].arg, vArgs[i].arg_long, vArgs[i].arg_description);
	}
	exit(1);
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		LCD_Init();
		int i = 1;
		while (i < argc)
		{
			if ((strcmp(argv[i], "-b") == 0) || (strcmp(argv[i], "--setBrightness") == 0))
			{
				if (i + 1 <= argc)
				{
					int brightness;
					if (argv[i + 1] == NULL)
					{
						fprintf(stderr, "Missing brightness value\n");
						usage(argv[0], NULL);
					}
					brightness = atoi(argv[i + 1]);
					if (brightness < 0 || brightness > 10)
					{
						fprintf(stderr, "Brightness value out of range\n");
						usage(argv[0], NULL);
					}
					/* set display brightness */
					LCD_brightness(brightness);
				}
				i += 1;
			}
			else if ((strcmp(argv[i], "-c") == 0) || (strcmp(argv[i], "--clear") == 0))
			{
				/* clear the display */
				LCD_Clear();
			}
			else if ((strcmp(argv[i], "-tu") == 0) || (strcmp(argv[i], "--setTextUp") == 0))
			{
				if (i + 1 <= argc)
				{
					char *text;
					if (argv[i + 1] == NULL)
					{
						fprintf(stderr, "Missing text value\n");
						usage(argv[0], NULL);
					}
					text = argv[i + 1];
					/* set display text */
					int text_length = strlen(text) * 4;
					if (text_length > 120/2)
						text_length = 120/2;
					LCD_draw_string(120/2-text_length, 15, text);
					LCD_update();
				}
				i += 1;
			}
			else if ((strcmp(argv[i], "-tc") == 0) || (strcmp(argv[i], "--setTextCenter") == 0))
			{
				if (i + 1 <= argc)
				{
					char *text;
					if (argv[i + 1]== NULL)
					{
						fprintf(stderr, "Missing text value\n");
						usage(argv[0], NULL);
					}
					text = argv[i + 1];
					/* set display text */
					int text_length = strlen(text) * 4;
					if (text_length > 120/2)
						text_length = 120/2;
					LCD_draw_string(120/2-text_length, 30, text);
					LCD_update();
				}
				i += 1;
			}
			else if ((strcmp(argv[i], "-td") == 0) || (strcmp(argv[i], "--setTextDown") == 0))
			{
				if (i + 1 <= argc)
				{
					char *text;
					if (argv[i + 1] == NULL)
					{
						fprintf(stderr, "Missing text value\n");
						usage(argv[0], NULL);
					}
					text = argv[i + 1];
					/* set display text */
					int text_length = strlen(text) * 4;
					if (text_length > 120/2)
						text_length = 120/2;
					LCD_draw_string(120/2-text_length, 45, text);
					LCD_update();
				}
				i += 1;
			}
			else
			{
				usage(argv[0], NULL);
			}
			i++;
		}
	}
	else
	{
		usage(argv[0], NULL);
	}
	LCD_Close();
	return 0;
}
