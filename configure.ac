dnl AC_PREREQ([2.69])
AC_INIT([oftc-ircd], [0.0.1])
AM_INIT_AUTOMAKE([foreign])

LT_INIT

AC_CONFIG_MACRO_DIR([m4])

AC_LIBTOOL_DLOPEN
AM_ENABLE_SHARED

AC_PROG_INSTALL
AC_PROG_CC
AC_PROG_CC_STDC

AC_DEFUN([AX_ARG_ENABLE_DEBUGGING],[
  AC_ARG_ENABLE([debugging],[AC_HELP_STRING([--enable-debugging],[Enable debugging.])],[debugging="$enableval"],[debugging="no"])
  if test "$debugging" = "yes" ; then
    AC_DEFINE([DEBUG],[1],[Define to 1 to enable debugging.])
    CFLAGS="$CFLAGS -Wall -Werror -Weverything -Wno-missing-braces -Wno-padded -Wno-unused-parameter -Wno-documentation -Wno-gnu -Wno-used-but-marked-unused -Wno-missing-field-initializers -Wno-static-in-inline -Wno-missing-variable-declarations -g -O0"
  else
    AC_DEFINE([NDEBUG],[1],[Define to 1 to disable debugging.])
  fi
])

AX_ARG_ENABLE_DEBUGGING

AC_CONFIG_SUBDIRS([libuv json-c])
AC_CONFIG_FILES([ Makefile          \
                  src/Makefile      \
                  modules/Makefile  \
                  include/Makefile  \
                  tests/Makefile])

AC_OUTPUT
