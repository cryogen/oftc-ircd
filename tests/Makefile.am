TESTS = oftc_ircd_tests client_tests
check_PROGRAMS = oftc_ircd_tests client_tests

client_tests_SOURCES = client_tests.c

AM_LDFLAGS = --coverage

client_tests_LDADD =    memory_stub.o           \
                        vector_stub.o           \
                        hash_stub.o             \
                        uv_stub.o               \
                        opmock.o                \
                        ../src/client.o         

oftc_ircd_tests_SOURCES =   config_tests.c      \
                            hash_tests.c        \
                            listener_tests.c    \
                            lstring_tests.c     \
                            oftc_ircd_tests.c   \
                            opmock.c            \
                            vector_tests.c

AM_CPPFLAGS = -g -O0 @CHECK_CFLAGS@ -I$(top_builddir)/include -I$(top_builddir) \
                -I$(top_builddir)/libuv/include
oftc_ircd_tests_LDADD = $(top_builddir)/src/libircd.la @CHECK_LIBS@ \
                $(top_builddir)/json-c/libjson-c.la $(top_builddir)/libuv/libuv.la
