ACLOCAL_AMFLAGS = -I m4

if BOXMODEL_DM800SE
bin_PROGRAMS = oled
oled_SOURCES = lcd.c
else
if BOXMODEL_DM800SEV2
bin_PROGRAMS = oled
oled_SOURCES = lcd.c
else
bin_PROGRAMS = lcd
lcd_SOURCES = lcd.c
endif
endif
