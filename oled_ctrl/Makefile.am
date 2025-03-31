AM_CPPFLAGS = \
	@FREETYPE_CFLAGS@

ACLOCAL_AMFLAGS = -I m4

if BOXMODEL_DM8000
bin_PROGRAMS = oled_c
oled_c_SOURCES = oled_freetype.c oled_driver.c oled_main.c
oled_c_LDADD = -lfreetype
else
if BOXMODEL_DM7020HD
bin_PROGRAMS = oled_c
oled_c_SOURCES = oled_freetype.c oled_driver.c oled_main.c
oled_c_LDADD = -lfreetype
else
if BOXMODEL_DM7080
bin_PROGRAMS = oled_c
oled_c_SOURCES = oled_freetype.c oled_driver.c oled_main.c
oled_c_LDADD = -lfreetype
else
bin_PROGRAMS = oled
oled_SOURCES = oled_freetype.c oled_driver.c oled_main.c
oled_LDADD = -lfreetype
endif
endif
endif
