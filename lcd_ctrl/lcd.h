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

#ifndef __lcddisplay__
#define __lcddisplay__

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define LCD_DEVICE	"/dev/dbox/lcd0"
#define LCD_BRIGHTNESS	"/proc/stb/lcd/oled_brightness"

#define LCD_PIXEL_OFF	0
#define LCD_PIXEL_ON	1
#define LCD_PIXEL_INV	2

#define LCD_ROWS	8
#define LCD_COLS	120

enum
{
	PIXEL_ON =	LCD_PIXEL_ON,
	PIXEL_OFF =	LCD_PIXEL_OFF,
	PIXEL_INV =	LCD_PIXEL_INV
};

int LCD_Init(void);
void LCD_Clear(void);
int LCD_Close(void);

int LCD_invalid_col(int x);
int LCD_invalid_row(int y);
void LCD_convert_data();
int LCD_brightness(int brightness);
void LCD_update();
void LCD_Read(void);

void LCD_draw_point (int x,int y, int state);
void LCD_draw_char(int x, int y, unsigned char c);
void LCD_draw_string(int x, int y, unsigned char *string);

#endif
