AC_DEFUN([AX_ARG_ENABLE_DEBUGGING],[
  AC_ARG_ENABLE([debugging],[AC_HELP_STRING([--enable-debugging],[Enable debuggi
ng.])],[debugging="$enableval"],[debugging="no"])
  if test "$debugging" = "yes" ; then
    AC_DEFINE([DEBUG],[1],[Define to 1 to enable debugging.])
    CFLAGS="$CFLAGS -Wall -Werror -Weverything -Wno-missing-braces -Wno-padded -Wno-unused-parameter -Wno-documentation -Wno-gnu -Wno-used-but-marked-unused -Wno-missing-field-initializers -Wno-static-in-inline -Wno-missing-variable-declarations -g -O0"
  else
    AC_DEFINE([NDEBUG],[1],[Define to 1 to disable debugging.])
  fi
])

