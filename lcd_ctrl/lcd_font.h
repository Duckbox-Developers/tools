/*
 * lcd for DM800SE/DM800SEV2/DM8000/DM7020/DM7080
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

#define FONTDATAMAX 2048

static unsigned char font[FONTDATAMAX] = {

	/* 0 0x00 '^@' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 1 0x01 '^A' */
	0x7e, /*  XXXXXX  */
	0x81, /* X      X */
	0xa5, /* X X  X X */
	0x81, /* X      X */
	0xbd, /* X XXXX X */
	0x99, /* X  XX  X */
	0x81, /* X      X */
	0x7e, /*  XXXXXX  */

	/* 2 0x02 '^B' */
	0x7e, /*  XXXXXX  */
	0xff, /* XXXXXXXX */
	0xdb, /* XX XX XX */
	0xff, /* XXXXXXXX */
	0xc3, /* XX    XX */
	0xe7, /* XXX  XXX */
	0xff, /* XXXXXXXX */
	0x7e, /*  XXXXXX  */

	/* 3 0x03 '^C' */
	0x6c, /*  XX XX   */
	0xfe, /* XXXXXXX  */
	0xfe, /* XXXXXXX  */
	0xfe, /* XXXXXXX  */
	0x7c, /*  XXXXX   */
	0x38, /*   XXX    */
	0x10, /*    X     */
	0x00, /*          */

	/* 4 0x04 '^D' */
	0x10, /*    X     */
	0x38, /*   XXX    */
	0x7c, /*  XXXXX   */
	0xfe, /* XXXXXXX  */
	0x7c, /*  XXXXX   */
	0x38, /*   XXX    */
	0x10, /*    X     */
	0x00, /*          */

	/* 5 0x05 '^E' */
	0x38, /*   XXX    */
	0x7c, /*  XXXXX   */
	0x38, /*   XXX    */
	0xfe, /* XXXXXXX  */
	0xfe, /* XXXXXXX  */
	0xd6, /* XX X XX  */
	0x10, /*    X     */
	0x38, /*   XXX    */

	/* 6 0x06 '^F' */
	0x10, /*    X     */
	0x38, /*   XXX    */
	0x7c, /*  XXXXX   */
	0xfe, /* XXXXXXX  */
	0xfe, /* XXXXXXX  */
	0x7c, /*  XXXXX   */
	0x10, /*    X     */
	0x38, /*   XXX    */

	/* 7 0x07 '^G' */
	0x00, /*          */
	0x00, /*          */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x00, /*          */
	0x00, /*          */

	/* 8 0x08 '^H' */
	0xff, /* XXXXXXXX */
	0xff, /* XXXXXXXX */
	0xe7, /* XXX  XXX */
	0xc3, /* XX    XX */
	0xc3, /* XX    XX */
	0xe7, /* XXX  XXX */
	0xff, /* XXXXXXXX */
	0xff, /* XXXXXXXX */

	/* 9 0x09 '^I' */
	0x00, /*          */
	0x3c, /*   XXXX   */
	0x66, /*  XX  XX  */
	0x42, /*  X    X  */
	0x42, /*  X    X  */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */
	0x00, /*          */

	/* 10 0x0a '^J' */
	0xff, /* XXXXXXXX */
	0xc3, /* XX    XX */
	0x99, /* X  XX  X */
	0xbd, /* X XXXX X */
	0xbd, /* X XXXX X */
	0x99, /* X  XX  X */
	0xc3, /* XX    XX */
	0xff, /* XXXXXXXX */

	/* 11 0x0b '^K' */
	0x0f, /*     XXXX */
	0x07, /*      XXX */
	0x0f, /*     XXXX */
	0x7d, /*  XXXXX X */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0x78, /*  XXXX    */

	/* 12 0x0c '^L' */
	0x3c, /*   XXXX   */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */

	/* 13 0x0d '^M' */
	0x3f, /*   XXXXXX */
	0x33, /*   XX  XX */
	0x3f, /*   XXXXXX */
	0x30, /*   XX     */
	0x30, /*   XX     */
	0x70, /*  XXX     */
	0xf0, /* XXXX     */
	0xe0, /* XXX      */

	/* 14 0x0e '^N' */
	0x7f, /*  XXXXXXX */
	0x63, /*  XX   XX */
	0x7f, /*  XXXXXXX */
	0x63, /*  XX   XX */
	0x63, /*  XX   XX */
	0x67, /*  XX  XXX */
	0xe6, /* XXX  XX  */
	0xc0, /* XX       */

	/* 15 0x0f '^O' */
	0x18, /*    XX    */
	0xdb, /* XX XX XX */
	0x3c, /*   XXXX   */
	0xe7, /* XXX  XXX */
	0xe7, /* XXX  XXX */
	0x3c, /*   XXXX   */
	0xdb, /* XX XX XX */
	0x18, /*    XX    */

	/* 16 0x10 '^P' */
	0x80, /* X        */
	0xe0, /* XXX      */
	0xf8, /* XXXXX    */
	0xfe, /* XXXXXXX  */
	0xf8, /* XXXXX    */
	0xe0, /* XXX      */
	0x80, /* X        */
	0x00, /*          */

	/* 17 0x11 '^Q' */
	0x02, /*       X  */
	0x0e, /*     XXX  */
	0x3e, /*   XXXXX  */
	0xfe, /* XXXXXXX  */
	0x3e, /*   XXXXX  */
	0x0e, /*     XXX  */
	0x02, /*       X  */
	0x00, /*          */

	/* 18 0x12 '^R' */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */

	/* 19 0x13 '^S' */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x00, /*          */
	0x66, /*  XX  XX  */
	0x00, /*          */

	/* 20 0x14 '^T' */
	0x7f, /*  XXXXXXX */
	0xdb, /* XX XX XX */
	0xdb, /* XX XX XX */
	0x7b, /*  XXXX XX */
	0x1b, /*    XX XX */
	0x1b, /*    XX XX */
	0x1b, /*    XX XX */
	0x00, /*          */

	/* 21 0x15 '^U' */
	0x3e, /*   XXXXX  */
	0x61, /*  XX    X */
	0x3c, /*   XXXX   */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */
	0x86, /* X    XX  */
	0x7c, /*  XXXXX   */

	/* 22 0x16 '^V' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0x7e, /*  XXXXXX  */
	0x7e, /*  XXXXXX  */
	0x00, /*          */

	/* 23 0x17 '^W' */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0xff, /* XXXXXXXX */

	/* 24 0x18 '^X' */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 25 0x19 '^Y' */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x00, /*          */

	/* 26 0x1a '^Z' */
	0x00, /*          */
	0x18, /*    XX    */
	0x0c, /*     XX   */
	0xfe, /* XXXXXXX  */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x00, /*          */
	0x00, /*          */

	/* 27 0x1b '^[' */
	0x00, /*          */
	0x30, /*   XX     */
	0x60, /*  XX      */
	0xfe, /* XXXXXXX  */
	0x60, /*  XX      */
	0x30, /*   XX     */
	0x00, /*          */
	0x00, /*          */

	/* 28 0x1c '^\' */
	0x00, /*          */
	0x00, /*          */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xfe, /* XXXXXXX  */
	0x00, /*          */
	0x00, /*          */

	/* 29 0x1d '^]' */
	0x00, /*          */
	0x24, /*   X  X   */
	0x66, /*  XX  XX  */
	0xff, /* XXXXXXXX */
	0x66, /*  XX  XX  */
	0x24, /*   X  X   */
	0x00, /*          */
	0x00, /*          */

	/* 30 0x1e '^^' */
	0x00, /*          */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x7e, /*  XXXXXX  */
	0xff, /* XXXXXXXX */
	0xff, /* XXXXXXXX */
	0x00, /*          */
	0x00, /*          */

	/* 31 0x1f '^_' */
	0x00, /*          */
	0xff, /* XXXXXXXX */
	0xff, /* XXXXXXXX */
	0x7e, /*  XXXXXX  */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x00, /*          */
	0x00, /*          */

	/* 32 0x20 ' ' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 33 0x21 '!' */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x3c, /*   XXXX   */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x00, /*          */
	0x18, /*    XX    */
	0x00, /*          */

	/* 34 0x22 '"' */
	0x6c, /*  XX XX   */
	0x6c, /*  XX XX   */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 35 0x23 '#' */
	0x6c, /*  XX XX   */
	0x6c, /*  XX XX   */
	0xfe, /* XXXXXXX  */
	0x6c, /*  XX XX   */
	0xfe, /* XXXXXXX  */
	0x6c, /*  XX XX   */
	0x6c, /*  XX XX   */
	0x00, /*          */

	/* 36 0x24 '$' */
	0x18, /*    XX    */
	0x3e, /*   XXXXX  */
	0x60, /*  XX      */
	0x3c, /*   XXXX   */
	0x06, /*      XX  */
	0x7c, /*  XXXXX   */
	0x18, /*    XX    */
	0x00, /*          */

	/* 37 0x25 '%' */
	0x00, /*          */
	0xc6, /* XX   XX  */
	0xcc, /* XX  XX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x66, /*  XX  XX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 38 0x26 '&' */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0x68, /*  XX X    */
	0x76, /*  XXX XX  */
	0xdc, /* XX XXX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 39 0x27 ''' */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 40 0x28 '(' */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x30, /*   XX     */
	0x30, /*   XX     */
	0x18, /*    XX    */
	0x0c, /*     XX   */
	0x00, /*          */

	/* 41 0x29 ')' */
	0x30, /*   XX     */
	0x18, /*    XX    */
	0x0c, /*     XX   */
	0x0c, /*     XX   */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x00, /*          */

	/* 42 0x2a '*' */
	0x00, /*          */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */
	0xff, /* XXXXXXXX */
	0x3c, /*   XXXX   */
	0x66, /*  XX  XX  */
	0x00, /*          */
	0x00, /*          */

	/* 43 0x2b '+' */
	0x00, /*          */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */
	0x00, /*          */

	/* 44 0x2c ',' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x30, /*   XX     */

	/* 45 0x2d '-' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 46 0x2e '.' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 47 0x2f '/' */
	0x03, /*       XX */
	0x06, /*      XX  */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x60, /*  XX      */
	0xc0, /* XX       */
	0x00, /*          */

	/* 48 0x30 '0' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xde, /* XX XXXX  */
	0xfe, /* XXXXXXX  */
	0xf6, /* XXXX XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 49 0x31 '1' */
	0x18, /*    XX    */
	0x78, /*  XXXX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 50 0x32 '2' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x60, /*  XX      */
	0xfe, /* XXXXXXX  */
	0x00, /*          */

	/* 51 0x33 '3' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0x06, /*      XX  */
	0x1c, /*    XXX   */
	0x06, /*      XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 52 0x34 '4' */
	0x1c, /*    XXX   */
	0x3c, /*   XXXX   */
	0x6c, /*  XX XX   */
	0xcc, /* XX  XX   */
	0xfe, /* XXXXXXX  */
	0x0c, /*     XX   */
	0x0c, /*     XX   */
	0x00, /*          */

	/* 53 0x35 '5' */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0xfc, /* XXXXXX   */
	0x06, /*      XX  */
	0x06, /*      XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 54 0x36 '6' */
	0x38, /*   XXX    */
	0x60, /*  XX      */
	0xc0, /* XX       */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 55 0x37 '7' */
	0xfe, /* XXXXXXX  */
	0x06, /*      XX  */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x60, /*  XX      */
	0x60, /*  XX      */
	0x00, /*          */

	/* 56 0x38 '8' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 57 0x39 '9' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7e, /*  XXXXXX  */
	0x06, /*      XX  */
	0x0c, /*     XX   */
	0x38, /*   XXX    */
	0x00, /*          */

	/* 58 0x3a ':' */
	0x00, /*          */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */
	0x00, /*          */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 59 0x3b ';' */
	0x00, /*          */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */
	0x00, /*          */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x30, /*   XX     */

	/* 60 0x3c '<' */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x60, /*  XX      */
	0x30, /*   XX     */
	0x18, /*    XX    */
	0x0c, /*     XX   */
	0x00, /*          */

	/* 61 0x3d '=' */
	0x00, /*          */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0x00, /*          */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0x00, /*          */
	0x00, /*          */

	/* 62 0x3e '>' */
	0x30, /*   XX     */
	0x18, /*    XX    */
	0x0c, /*     XX   */
	0x06, /*      XX  */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x00, /*          */

	/* 63 0x3f '?' */
	0x3c, /*   XXXX   */
	0x66, /*  XX  XX  */
	0x06, /*      XX  */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x00, /*          */
	0x18, /*    XX    */
	0x00, /*          */

	/* 64 0x40 '@' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xde, /* XX XXXX  */
	0xde, /* XX XXXX  */
	0xde, /* XX XXXX  */
	0xc0, /* XX       */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 65 0x41 'A' */
	0x10, /*    X     */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 66 0x42 'B' */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xfc, /* XXXXXX   */
	0x00, /*          */

	/* 67 0x43 'C' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 68 0x44 'D' */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xfc, /* XXXXXX   */
	0x00, /*          */

	/* 69 0x45 'E' */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xf8, /* XXXXX    */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xfe, /* XXXXXXX  */
	0x00, /*          */

	/* 70 0x46 'F' */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xf8, /* XXXXX    */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0x00, /*          */

	/* 71 0x47 'G' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc0, /* XX       */
	0xce, /* XX  XXX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 72 0x48 'H' */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 73 0x49 'I' */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x00, /*          */

	/* 74 0x4a 'J' */
	0x06, /*      XX  */
	0x06, /*      XX  */
	0x06, /*      XX  */
	0x06, /*      XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 75 0x4b 'K' */
	0xc6, /* XX   XX  */
	0xcc, /* XX  XX   */
	0xd8, /* XX XX    */
	0xf0, /* XXXX     */
	0xd8, /* XX XX    */
	0xcc, /* XX  XX   */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 76 0x4c 'L' */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xfe, /* XXXXXXX  */
	0x00, /*          */

	/* 77 0x4d 'M' */
	0x82, /* X     X  */
	0xc6, /* XX   XX  */
	0xee, /* XXX XXX  */
	0xfe, /* XXXXXXX  */
	0xd6, /* XX X XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 78 0x4e 'N' */
	0xc6, /* XX   XX  */
	0xe6, /* XXX  XX  */
	0xf6, /* XXXX XX  */
	0xde, /* XX XXXX  */
	0xce, /* XX  XXX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 79 0x4f 'O' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 80 0x50 'P' */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xfc, /* XXXXXX   */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0x00, /*          */

	/* 81 0x51 'Q' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xf6, /* XXXX XX  */
	0xde, /* XX XXXX  */
	0x7c, /*  XXXXX   */
	0x06, /*      XX  */

	/* 82 0x52 'R' */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xfc, /* XXXXXX   */
	0xd8, /* XX XX    */
	0xcc, /* XX  XX   */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 83 0x53 'S' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0x60, /*  XX      */
	0x38, /*   XXX    */
	0x0c, /*     XX   */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 84 0x54 'T' */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 85 0x55 'U' */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 86 0x56 'V' */
	0xc3, /* XX    XX */
	0xc3, /* XX    XX */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x00, /*          */

	/* 87 0x57 'W' */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xd6, /* XX X XX  */
	0xfe, /* XXXXXXX  */
	0xee, /* XXX XXX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 88 0x58 'X' */
	0xc3, /* XX    XX */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x66, /*  XX  XX  */
	0xc3, /* XX    XX */
	0x00, /*          */

	/* 89 0x59 'Y' */
	0xc3, /* XX    XX */
	0xc3, /* XX    XX */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 90 0x5a 'Z' */
	0xfe, /* XXXXXXX  */
	0x06, /*      XX  */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x60, /*  XX      */
	0xfe, /* XXXXXXX  */
	0x00, /*          */

	/* 91 0x5b '[' */
	0x3c, /*   XXXX   */
	0x30, /*   XX     */
	0x30, /*   XX     */
	0x30, /*   XX     */
	0x30, /*   XX     */
	0x30, /*   XX     */
	0x3c, /*   XXXX   */
	0x00, /*          */

	/* 92 0x5c '\' */
	0xc0, /* XX       */
	0x60, /*  XX      */
	0x30, /*   XX     */
	0x18, /*    XX    */
	0x0c, /*     XX   */
	0x06, /*      XX  */
	0x03, /*       XX */
	0x00, /*          */

	/* 93 0x5d ']' */
	0x3c, /*   XXXX   */
	0x0c, /*     XX   */
	0x0c, /*     XX   */
	0x0c, /*     XX   */
	0x0c, /*     XX   */
	0x0c, /*     XX   */
	0x3c, /*   XXXX   */
	0x00, /*          */

	/* 94 0x5e '^' */
	0x10, /*    X     */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0xc6, /* XX   XX  */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 95 0x5f '_' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0xfe, /* XXXXXXX  */

	/* 96 0x60 '`' */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x0c, /*     XX   */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 97 0x61 'a' */
	0x00, /*          */
	0x00, /*          */
	0x7c, /*  XXXXX   */
	0x06, /*      XX  */
	0x7e, /*  XXXXXX  */
	0xc6, /* XX   XX  */
	0x7e, /*  XXXXXX  */
	0x00, /*          */

	/* 98 0x62 'b' */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xfc, /* XXXXXX   */
	0x00, /*          */

	/* 99 0x63 'c' */
	0x00, /*          */
	0x00, /*          */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc0, /* XX       */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 100 0x64 'd' */
	0x06, /*      XX  */
	0x06, /*      XX  */
	0x7e, /*  XXXXXX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7e, /*  XXXXXX  */
	0x00, /*          */

	/* 101 0x65 'e' */
	0x00, /*          */
	0x00, /*          */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 102 0x66 'f' */
	0x3c, /*   XXXX   */
	0x66, /*  XX  XX  */
	0x60, /*  XX      */
	0xf0, /* XXXX     */
	0x60, /*  XX      */
	0x60, /*  XX      */
	0x60, /*  XX      */
	0x00, /*          */

	/* 103 0x67 'g' */
	0x00, /*          */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7e, /*  XXXXXX  */
	0x06, /*      XX  */
	0x7c, /*  XXXXX   */

	/* 104 0x68 'h' */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 105 0x69 'i' */
	0x18, /*    XX    */
	0x00, /*          */
	0x38, /*   XXX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 106 0x6a 'j' */
	0x06, /*      XX  */
	0x00, /*          */
	0x06, /*      XX  */
	0x06, /*      XX  */
	0x06, /*      XX  */
	0x06, /*      XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */

	/* 107 0x6b 'k' */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xcc, /* XX  XX   */
	0xd8, /* XX XX    */
	0xf0, /* XXXX     */
	0xd8, /* XX XX    */
	0xcc, /* XX  XX   */
	0x00, /*          */

	/* 108 0x6c 'l' */
	0x38, /*   XXX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 109 0x6d 'm' */
	0x00, /*          */
	0x00, /*          */
	0xec, /* XXX XX   */
	0xfe, /* XXXXXXX  */
	0xd6, /* XX X XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 110 0x6e 'n' */
	0x00, /*          */
	0x00, /*          */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 111 0x6f 'o' */
	0x00, /*          */
	0x00, /*          */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 112 0x70 'p' */
	0x00, /*          */
	0x00, /*          */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xfc, /* XXXXXX   */
	0xc0, /* XX       */
	0xc0, /* XX       */

	/* 113 0x71 'q' */
	0x00, /*          */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7e, /*  XXXXXX  */
	0x06, /*      XX  */
	0x06, /*      XX  */

	/* 114 0x72 'r' */
	0x00, /*          */
	0x00, /*          */
	0xdc, /* XX XXX   */
	0xe6, /* XXX  XX  */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0x00, /*          */

	/* 115 0x73 's' */
	0x00, /*          */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0xc0, /* XX       */
	0x7c, /*  XXXXX   */
	0x06, /*      XX  */
	0xfc, /* XXXXXX   */
	0x00, /*          */

	/* 116 0x74 't' */
	0x30, /*   XX     */
	0x30, /*   XX     */
	0x7c, /*  XXXXX   */
	0x30, /*   XX     */
	0x30, /*   XX     */
	0x36, /*   XX XX  */
	0x1c, /*    XXX   */
	0x00, /*          */

	/* 117 0x75 'u' */
	0x00, /*          */
	0x00, /*          */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 118 0x76 'v' */
	0x00, /*          */
	0x00, /*          */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x6c, /*  XX XX   */
	0x38, /*   XXX    */
	0x00, /*          */

	/* 119 0x77 'w' */
	0x00, /*          */
	0x00, /*          */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xd6, /* XX X XX  */
	0xfe, /* XXXXXXX  */
	0x6c, /*  XX XX   */
	0x00, /*          */

	/* 120 0x78 'x' */
	0x00, /*          */
	0x00, /*          */
	0xc6, /* XX   XX  */
	0x6c, /*  XX XX   */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 121 0x79 'y' */
	0x00, /*          */
	0x00, /*          */
	0xc3, /* XX    XX */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x60, /*  XX      */

	/* 122 0x7a 'z' */
	0x00, /*          */
	0x00, /*          */
	0xfe, /* XXXXXXX  */
	0x0c, /*     XX   */
	0x38, /*   XXX    */
	0x60, /*  XX      */
	0xfe, /* XXXXXXX  */
	0x00, /*          */

	/* 123 0x7b '{' */
	0x0e, /*     XXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x70, /*  XXX     */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x0e, /*     XXX  */
	0x00, /*          */

	/* 124 0x7c '|' */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 125 0x7d '}' */
	0x70, /*  XXX     */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x0e, /*     XXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x70, /*  XXX     */
	0x00, /*          */

	/* 126 0x7e '~' */
	0x72, /*  XXX  X  */
	0x9c, /* X  XXX   */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 127 0x7f '' */
	0x00, /*          */
	0x10, /*    X     */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0x00, /*          */

	/* 128 0x80 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 129 0x81 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 130 0x82 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 131 0x83 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 132 0x84 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 133 0x85 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 134 0x86 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 135 0x87 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 136 0x88 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 137 0x89 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 138 0x8a '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 139 0x8b '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 140 0x8c '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 141 0x8d '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 142 0x8e '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 143 0x8f '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 144 0x90 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 145 0x91 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 146 0x92 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 147 0x93 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 148 0x94 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 149 0x95 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 150 0x96 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 151 0x97 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 152 0x98 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 153 0x99 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 154 0x9a '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 155 0x9b '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 156 0x9c '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 157 0x9d '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 158 0x9e '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 159 0x9f '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 160 0xa0 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 161 0xa1 '�' */
	0x18, /*    XX    */
	0x00, /*          */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x00, /*          */

	/* 162 0xa2 '�' */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */

	/* 163 0xa3 '�' */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0x64, /*  XX  X   */
	0xf0, /* XXXX     */
	0x60, /*  XX      */
	0x66, /*  XX  XX  */
	0xfc, /* XXXXXX   */
	0x00, /*          */

	/* 164 0xa4 '�' */
	0x00, /*          */
	0x99, /* X  XX  X */
	0x42, /*  X    X  */
	0x81, /* X      X */
	0x81, /* X      X */
	0x42, /*  X    X  */
	0x99, /* X  XX  X */
	0x00, /*          */

	/* 165 0xa5 '�' */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */

	/* 166 0xa6 '�' */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 167 0xa7 '�' */
	0x3c, /*   XXXX   */
	0x20, /*   X      */
	0x70, /*  XXX     */
	0x6c, /*  XX XX   */
	0x36, /*   XX XX  */
	0x1e, /*    XXXX  */
	0x08, /*     X    */
	0x78, /*  XXXX    */

	/* 168 0xa8 '�' */
	0x00, /*          */
	0x24, /*   X  X   */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 169 0xa9 '�' */
	0x3c, /*   XXXX   */
	0x42, /*  X    X  */
	0x99, /* X  XX  X */
	0xa1, /* X X    X */
	0xa1, /* X X    X */
	0x99, /* X  XX  X */
	0x42, /*  X    X  */
	0x3c, /*   XXXX   */

	/* 170 0xaa '�' */
	0x3c, /*   XXXX   */
	0x6c, /*  XX XX   */
	0x6c, /*  XX XX   */
	0x3e, /*   XXXXX  */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 171 0xab '�' */
	0x00, /*          */
	0x33, /*   XX  XX */
	0x66, /*  XX  XX  */
	0xcc, /* XX  XX   */
	0x66, /*  XX  XX  */
	0x33, /*   XX  XX */
	0x00, /*          */
	0x00, /*          */

	/* 172 0xac '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0xfe, /* XXXXXXX  */
	0x06, /*      XX  */
	0x06, /*      XX  */
	0x00, /*          */
	0x00, /*          */

	/* 173 0xad '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x18, /*    XX    */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 174 0xae '�' */
	0x3c, /*   XXXX   */
	0x42, /*  X    X  */
	0xb9, /* X XXX  X */
	0xa5, /* X X  X X */
	0xb9, /* X XXX  X */
	0xa5, /* X X  X X */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */

	/* 175 0xaf '�' */
	0x7e, /*  XXXXXX  */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 176 0xb0 '�' */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0x6c, /*  XX XX   */
	0x38, /*   XXX    */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 177 0xb1 '�' */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0x00, /*          */

	/* 178 0xb2 '�' */
	0x78, /*  XXXX    */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x7c, /*  XXXXX   */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 179 0xb3 '�' */
	0x18, /*    XX    */
	0x04, /*      X   */
	0x18, /*    XX    */
	0x04, /*      X   */
	0x18, /*    XX    */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 180 0xb4 '�' */
	0x0c, /*     XX   */
	0x10, /*    X     */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 181 0xb5 '�' */
	0x00, /*          */
	0x00, /*          */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x7c, /*  XXXXX   */
	0xc0, /* XX       */

	/* 182 0xb6 '�' */
	0x3b, /*   XXX XX */
	0x4a, /*  X  X X  */
	0x4a, /*  X  X X  */
	0x3a, /*   XXX X  */
	0x0a, /*     X X  */
	0x0a, /*     X X  */
	0x1b, /*    XX XX */
	0x00, /*          */

	/* 183 0xb7 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x18, /*    XX    */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 184 0xb8 '�' */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x08, /*     X    */
	0x04, /*      X   */
	0x38, /*   XXX    */

	/* 185 0xb9 '�' */
	0x08, /*     XX   */
	0x18, /*    XXX   */
	0x08, /*     XX   */
	0x08, /*     XX   */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */

	/* 186 0xba '�' */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0x6c, /*  XX XX   */
	0x38, /*   XXX    */
	0x00, /*          */
	0x7c, /*  XXXXX   */
	0x00, /*          */
	0x00, /*          */

	/* 187 0xbb '�' */
	0x00, /*          */
	0xcc, /* XX  XX   */
	0x66, /*  XX  XX  */
	0x33, /*   XX  XX */
	0x66, /*  XX  XX  */
	0xcc, /* XX  XX   */
	0x00, /*          */
	0x00, /*          */

	/* 188 0xbc '�' */
	0x63, /*  XX   XX */
	0xe6, /* XXX  XX  */
	0x6c, /*  XX XX   */
	0x7a, /*  XXXX X  */
	0x36, /*   XX XX  */
	0x6a, /*  XX X X  */
	0xdf, /* XX XXXXX */
	0x06, /*      XX  */

	/* 189 0xbd '�' */
	0x63, /*  XX   XX */
	0xe6, /* XXX  XX  */
	0x6c, /*  XX XX   */
	0x7e, /*  XXXXXX  */
	0x33, /*   XX  XX */
	0x66, /*  XX  XX  */
	0xcc, /* XX  XX   */
	0x0f, /*     XXXX */

	/* 190 0xbe '�' */
	0x63, /*  XX   XX */
	0x16, /*    X XX  */
	0x6c, /*  XX XX   */
	0x1a, /*    XX X  */
	0xf6, /* XXXX XX  */
	0x6a, /*  XX X X  */
	0xdf, /* XX XXXXX */
	0x06, /*      XX  */

	/* 191 0xbf '�' */
	0x18, /*    XX    */
	0x00, /*          */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x63, /*  XX   XX */
	0x3e, /*   XXXXX  */
	0x00, /*          */

	/* 192 0xc0 '�' */
	0x30, /*   XX     */
	0x08, /*     X    */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 193 0xc1 '�' */
	0x0c, /*     XX   */
	0x10, /*    X     */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 194 0xc2 '�' */
	0x18, /*    XX    */
	0x24, /*   X  X   */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 195 0xc3 '�' */
	0x14, /*    X X   */
	0x28, /*   X X    */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc6, /* XX   XX  */
	0x00, /*          */
   
	/* 196 0xc4 '�' */
	0xc6, /* XX   XX  */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 197 0xc5 '�' */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x00, /*          */

	/* 198 0xc6 '�' */
	0x3e, /*   XXXXX  */
	0x6c, /*  XX XX   */
	0xcc, /* XX  XX   */
	0xfe, /* XXXXXXX  */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0xce, /* XX  XXX  */
	0x00, /*          */

	/* 199 0xc7 '�' */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x0c, /*     XX   */
	0x78, /*  XXXX    */

	/* 200 0xc8 '�' */
	0x30, /*   XX     */
	0x08, /*     X    */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0xf8, /* XXXXX    */
	0xc0, /* XX       */
	0xfe, /* XXXXXXX  */
	0x00, /*          */

	/* 201 0xc9 '�' */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0xf8, /* XXXXX    */
	0xc0, /* XX       */
	0xfe, /* XXXXXXX  */
	0x00, /*          */
 
	/* 202 0xca '�' */
	0x18, /*    XX    */
	0x24, /*   X  X   */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0xf8, /* XXXXX    */
	0xc0, /* XX       */
	0xfe, /* XXXXXXX  */
	0x00, /*          */

	/* 203 0xcb '�' */
	0x24, /*   X  X   */
	0x00, /*          */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0xf8, /* XXXXX    */
	0xc0, /* XX       */
	0xfe, /* XXXXXXX  */
	0x00, /*          */

	/* 204 0xcc '�' */
	0x30, /*   XX     */
	0x08, /*     X    */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x00, /*          */

	/* 205 0xcd '�' */
	0x0c, /*     XX   */
	0x10, /*    X     */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x00, /*          */

	/* 206 0xce '�' */
	0x18, /*    XX    */
	0x24, /*   X  X   */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x00, /*          */

	/* 207 0xcf '�' */
	0x24, /*   X  X   */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0x00, /*          */

	/* 208 0xd0 '�' */
	0xfc, /* XXXXXX   */
	0xc6, /* XX   XX  */
	0xf6, /* XXXX XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xfc, /* XXXXXX   */
	0x00, /*          */

	/* 209 0xd1 '�' */
	0x76, /*  XXX XX  */
	0xdc, /* XX XXX   */
	0x00, /*          */
	0xe6, /* XXX  XX  */
	0xf6, /* XXXX XX  */
	0xde, /* XX XXXX  */
	0xce, /* XX  XXX  */
	0x00, /*          */

	/* 210 0xd2 '�' */
	0x30, /*   XX     */
	0x08, /*     X    */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 211 0xd3 '�' */
	0x0c, /*     XX   */
	0x10, /*    X     */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 212 0xd4 '�' */
	0x18, /*    XX    */
	0x24, /*   X  X   */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 213 0xd5 '�' */
	0x34, /*   XX X   */
	0x0c, /*     XX   */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 214 0xd6 '�' */
	0xc6, /* XX   XX  */
	0x38, /*   XXX    */
	0x6c, /*  XX XX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x6c, /*  XX XX   */
	0x38, /*   XXX    */
	0x00, /*          */

	/* 215 0xd7 '�' */
	0x00, /*          */
	0x00, /*          */
	0xc3, /* XX    XX */
	0x66, /*  XX  XX  */
	0x18, /*    XX    */
	0x66, /*  XX  XX  */
	0xc3, /* XX    XX */
	0x00, /*          */

	/* 216 0xd8 '�' */
	0x19, /*    XX  X */
	0x26, /*   X  XX  */
	0x46, /*  X   XX  */
	0x4a, /*  X  X X  */
	0x52, /*  X X  X  */
	0x24, /*   X  X   */
	0x58, /*  X XX    */
	0x00, /*          */

	/* 217 0xd9 '�' */
	0x30, /*   XX     */
	0x08, /*     X    */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 218 0xda '�' */
	0x0c, /*     XX   */
	0x10, /*    X     */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 219 0xdb '�' */
	0x18, /*    XX    */
	0x24, /*   X  X   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 220 0xdc '�' */
	0xc6, /* XX   XX  */
	0x00, /*          */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */
#if 0
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0x00, /*          */
	0xff, /* XXXXXXXX */
	0xff, /* XXXXXXXX */
	0xff, /* XXXXXXXX */
	0xff, /* XXXXXXXX */
#endif

	/* 221 0xdd '�' */
	0x0c, /*     XX   */
	0x10, /*    X     */
	0xc3, /* XX    XX */
	0x66, /*  XX  XX  */
	0x3c, /*   XXXX   */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x00, /*          */

	/* 222 0xde '�' */
	0x00, /*          */
	0x70, /*  XXX     */
	0x78, /*  XXXXX   */
	0x64, /*  XX  XX  */
	0x78, /*  XXXXX   */
	0x60, /*  XX      */
	0x78, /*  XXX     */
	0x00, /*          */

	/* 223 0xdf '�' */
	0x78, /*  XXXX    */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0xd8, /* XX XX    */
	0xcc, /* XX  XX   */
	0xc6, /* XX   XX  */
	0xcc, /* XX  XX   */
	0x00, /*          */

	/* 224 0xe0 '�' */
	0x30, /*   XX     */
	0x18, /*    XX    */
	0x78, /*  XXXX    */
	0x0c, /*     XX   */
	0x7c, /*  XXXXX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 225 0xe1 '�' */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x78, /*  XXXX    */
	0x0c, /*     XX   */
	0x7c, /*  XXXXX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 226 0xe2 '�' */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0x78, /*  XXXX    */
	0x0c, /*     XX   */
	0x7c, /*  XXXXX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 227 0xe3 '�' */
	0x14, /*    X X   */
	0x28, /*   X X    */
	0x78, /*  XXXX    */
	0x0c, /*     XX   */
	0x7c, /*  XXXXX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 228 0xe4 '�' */
	0xc6, /* XX   XX  */
	0x00, /*          */
	0x78, /*  XXXX    */
	0x0c, /*     XX   */
	0x7c, /*  XXXXX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 229 0xe5 '�' */
	0x30, /*   XX     */
	0x30, /*   XX     */
	0x78, /*  XXXX    */
	0x0c, /*     XX   */
	0x7c, /*  XXXXX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 230 0xe6 '�' */
	0x00, /*          */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0x18, /*    XX    */
	0x7e, /*  XXXXXX  */
	0xd8, /* XX XX    */
	0x7e, /*  XXXXXX  */
	0x00, /*          */

	/* 231 0xe7 '�' */
	0x00, /*          */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0xc0, /* XX       */
	0xc0, /* XX       */
	0x7e, /*  XXXXXX  */
	0x0c, /*     XX   */
	0x38, /*   XXX    */

	/* 232 0xe8 '�' */
	0x30, /*   XX     */
	0x18, /*    XX    */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 233 0xe9 '�' */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 234 0xea '�' */
	0x7c, /*  XXXXX   */
	0x82, /* X     X  */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 235 0xeb '�' */
	0xc6, /* XX   XX  */
	0x00, /*          */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xfe, /* XXXXXXX  */
	0xc0, /* XX       */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 236 0xec '�' */
	0x30, /*   XX     */
	0x18, /*    XX    */
	0x00, /*          */
	0x38, /*   XXX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x00, /*          */

	/* 237 0xed '�' */
	0x06, /*      XX  */
	0x0c, /*     XX   */
	0x7e, /*  XXXXXX  */
	0xdb, /* XX XX XX */
	0xdb, /* XX XX XX */
	0x7e, /*  XXXXXX  */
	0x60, /*  XX      */
	0xc0, /* XX       */

	/* 238 0xee '�' */
	0x7c, /*  XXXXX   */
	0x82, /* X     X  */
	0x38, /*   XXX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x00, /*          */

	/* 239 0xef '�' */
	0x66, /*  XX  XX  */
	0x00, /*          */
	0x38, /*   XXX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x18, /*    XX    */
	0x3c, /*   XXXX   */
	0x00, /*          */

	/* 240 0xf0 '�' */
	0x34, /*   XX X   */
	0x0c, /*     XX   */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 241 0xf1 '�' */
	0x76, /*  XXX XX  */
	0xdc, /* XX XXX   */
	0x00, /*          */
	0xdc, /* XX XXX   */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x66, /*  XX  XX  */
	0x00, /*          */

	/* 242 0xf2 '�' */
	0x30, /*   XX     */
	0x18, /*    XX    */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 243 0xf3 '�' */
	0x0c, /*     XX   */
	0x18, /*    XX    */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 244 0xf4 '�' */
	0x7c, /*  XXXXX   */
	0x82, /* X     X  */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 245 0xf5 '�' */
	0x14, /*    X X   */
	0x28, /*   X X    */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 246 0xf6 '�' */
	0xc6, /* XX   XX  */
	0x00, /*          */
	0x7c, /*  XXXXX   */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7c, /*  XXXXX   */
	0x00, /*          */

	/* 247 0xf7 '�' */
	0x00, /*          */
	0x18, /*    XX    */
	0x00, /*          */
	0x7e, /*  XXXXXX  */
	0x00, /*          */
	0x18, /*    XX    */
	0x00, /*          */
	0x00, /*          */

	/* 248 0xf8 '�' */
	0x00, /*          */
	0x1a, /*    XX X  */
	0x24, /*   X  X   */
	0x4a, /*  X  X X  */
	0x52, /*  X X  X  */
	0x24, /*   X  X   */
	0x58, /*  X XX    */
	0x00, /*          */

	/* 249 0xf9 '�' */
	0x60, /*  XX      */
	0x30, /*   XX     */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 250 0xfa '�' */
	0x18, /*    XX    */
	0x30, /*   XX     */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 251 0xfb '�' */
	0x78, /*  XXXX    */
	0x84, /* X    X   */
	0x00, /*          */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 252 0xfc '�' */
	0xcc, /* XX  XX   */
	0x00, /*          */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0xcc, /* XX  XX   */
	0x76, /*  XXX XX  */
	0x00, /*          */

	/* 253 0xfd '�' */
	0x0c, /*     XX   */
	0x10, /*    X     */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7e, /*  XXXXXX  */
	0x06, /*      XX  */
	0xfc, /* XXXXXX   */

	/* 254 0xfe '�' */
	0x70, /*  XXX     */
	0x60, /*  XX      */
	0x78, /*  XXXXX   */
	0x64, /*  XX  XX  */
	0x78, /*  XXXXX   */
	0x60, /*  XX      */
	0x78, /*  XXX     */
	0x00, /*          */

	/* 255 0xff '�' */
	0xc6, /* XX   XX  */
	0x00, /*          */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0xc6, /* XX   XX  */
	0x7e, /*  XXXXXX  */
	0x06, /*      XX  */
	0xfc, /* XXXXXX   */

};
