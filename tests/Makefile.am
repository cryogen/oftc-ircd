TESTS = oftc_ircd_tests
check_PROGRAMS = oftc_ircd_tests

oftc_ircd_tests_SOURCES =   oftc_ircd_tests.c   \
                            hash_tests.c        \
                            config_tests.c      \
                            listener_tests.c    \
                            vector_tests.c

AM_CPPFLAGS = @CHECK_CFLAGS@ -I$(top_builddir)/include -I$(top_builddir)
oftc_ircd_tests_LDADD = $(top_builddir)/src/libircd.la @CHECK_LIBS@ $(top_builddir)/json-c/libjson-c.la