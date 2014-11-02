TESTS = hash_tests
check_PROGRAMS = hash_tests
hash_tests_SOURCES = hash_tests.c $(top_builddir)/include/hash.h
hash_tests_CFLAGS = @CHECK_CFLAGS@ -I$(top_builddir)/include
hash_tests_LDADD = $(top_builddir)/src/libircd.la @CHECK_LIBS@
