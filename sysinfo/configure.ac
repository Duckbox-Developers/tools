AC_INIT([sysinfo],[1.24],[],[sysinfo])
AM_INIT_AUTOMAKE
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
m4_ifdef([LT_INIT], [LT_INIT], [AC_PROG_LIBTOOL])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
#AC_GNU_SOURCE

#TUXBOX_APPS
#TUXBOX_APPS_DIRECTORY
TUXBOX_BOXTYPE

AC_PROG_CC
AC_PROG_CXX

PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES(FREETYPE,freetype2)
PKG_CHECK_MODULES(PNG,libpng)

AC_OUTPUT([
Makefile
])
