TESTS = oftc_ircd_tests
check_PROGRAMS = oftc_ircd_tests

oftc_ircd_tests_SOURCES =   oftc_ircd_tests.c \
                            hash_tests.c \
                            config_tests.c

AM_CPPFLAGS = @CHECK_CFLAGS@ -I$(top_builddir)/include
oftc_ircd_tests_LDADD = $(top_builddir)/src/libircd.la @CHECK_LIBS@