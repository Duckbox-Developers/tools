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

void LCD_Read(void)
{
	int x, y, z;
	char tmp2;

	memset(raw, 0, 132 * 64);
	read(fd, &lcd, 120 * 64 / 8);
	for(x = 0; x < LCD_COLS; x++)
	{
		for(y = 0; y < LCD_ROWS; y++)
		{
			tmp2 = lcd[y][x];
			for(z = 0; z <= 7; z++)
			{
				if(tmp2 & (1 << z))
					raw[x][y * 8 + z] = 1;
			}
		}
	}
}

int LCD_Init(void)
{
	//open device
	if((fd = open(LCD_DEVICE, O_RDWR)) < 0)
	{
		perror("LCD open error");
		return -1;
	}

	LCD_Read();
	LCD_brightness(7);
	return 0;
}

void LCD_Clear(void)
{
	memcpy(raw, rawb, 132 * 64);
	LCD_update();
}

int LCD_Close(void)
{
	if(fd >= 0)
	{
		close(fd);
		fd = -1;
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
	int x, y, z;
	char tmp2;
	for(x = 0; x < LCD_COLS; x++) {
		for(y = 0; y < LCD_ROWS; y++) {
			tmp2 = 0;
			for(z = 0; z <= 7; z++) {
				if(raw[x][y * 8 + z] == 1) {
					tmp2 |= 1 << z;
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

	FILE *f = fopen(LCD_BRIGHTNESS, "w");
	if (f)
	{
		if (fprintf(f, "%d", value) == 0)
			printf("%s: write %s failed! (%m)\n", __FUNCTION__, LCD_BRIGHTNESS);
		fclose(f);
	}
	return 0;
}

void LCD_update()
{
	LCD_convert_data();
	write(fd, lcd, 120 * 64 / 8);
}

void LCD_draw_point (int x, int y, int state)
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

void LCD_draw_char(int x, int y, unsigned char c)
{
	int ax, ay;
	unsigned char *data = &font[8*c];

	for (ay = 0; ay < 8; ay++)
		for (ax = 0; ax < 8; ax++)
			if ((!LCD_invalid_col(x + ax)) && (!LCD_invalid_row(y + ay)))
				LCD_draw_point(x + ax, y + ay, data[ay] & (1 << (7 - ax)) ? PIXEL_ON : PIXEL_OFF);
}

void LCD_draw_string(int x, int y, unsigned char *string)
{
	unsigned char c;
	unsigned char d;
	while (*string)
	{
		c = *string++;
		switch (c)
		{
			case 0xC2:
				d = *string++;
				LCD_draw_char(x, y, d); x += 8; c = '\0'; break;
			case 0xC3:
				d = *string++ | 0xC0;
				LCD_draw_char(x, y, d); x += 8; c = '\0'; break;
			case 0xE2:
				*string++; *string++; c = '\0'; break;
		}
		if (c)
		{
			LCD_draw_char(x, y, c);
			x += 8;
		}
	}
}
