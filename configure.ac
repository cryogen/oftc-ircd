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

AC_CONFIG_SUBDIRS([libuv json-c])
AC_CONFIG_FILES([ Makefile      \
                  src/Makefile  \
                  include/Makefile
                  tests/Makefile])

AC_OUTPUT
