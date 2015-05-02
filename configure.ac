dnl AC_PREREQ([2.69])
AC_INIT([oftc-ircd], [0.0.1])

AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_SILENT_RULES([yes])
LT_INIT([dlopen])

AM_ENABLE_SHARED

CFLAGS="-g -Wall -Wextra -Wno-missing-braces -Wno-padded -Wno-unused-parameter \
        -Wno-documentation -Wno-gnu -Wno-used-but-marked-unused \
        -Wno-missing-field-initializers -Wno-static-in-inline \
        -Wno-missing-variable-declarations"

AC_PROG_INSTALL
AC_PROG_CC
AC_PROG_CC_STDC

CFLAGS="-Werror $CFLAGS"

AX_ARG_ENABLE_DEBUGGING
AX_ARG_ENABLE_PROFILING

C_FLAGS_CHECK([-Weverything])

AC_CONFIG_SUBDIRS([libuv json-c libtls])
AC_CONFIG_FILES([ Makefile          \
                  src/Makefile      \
                  modules/Makefile  \
                  include/Makefile  \
                  tests/Makefile])

AC_OUTPUT
