dnl AC_PREREQ([2.69])
AC_INIT([oftc-ircd], [0.0.1])

AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([foreign subdir-objects])
LT_INIT([dlopen])

AM_ENABLE_SHARED

AC_PROG_INSTALL
AC_PROG_CC
AC_PROG_CC_STDC

AX_ARG_ENABLE_DEBUGGING

AC_CONFIG_SUBDIRS([libuv json-c])
AC_CONFIG_FILES([ Makefile          \
                  src/Makefile      \
                  modules/Makefile  \
                  include/Makefile  \
                  tests/Makefile])

AC_OUTPUT
