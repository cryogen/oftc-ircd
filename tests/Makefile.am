TESTS = oftc_ircd_tests client_tests config_tests
check_PROGRAMS = oftc_ircd_tests client_tests config_tests

client_tests_SOURCES = client_tests.c
config_tests_SOURCES = config_tests.c

AM_LDFLAGS = --coverage

client_tests_LDADD =    memory_stub.o           \
                        vector_stub.o           \
                        hash_stub.o             \
                        uv_stub.o               \
                        opmock.o                \
                        ../src/client.o

config_tests_LDADD =    vector_stub.o           \
                        hash_stub.o             \
                        uv_stub.o               \
                        json_object_stub.o      \
                        json_tokener_stub.o     \
                        serverstate_stub.o      \
                        memory_stub.o           \
                        opmock.o                \
                        ../src/config.o         

oftc_ircd_tests_SOURCES =   hash_tests.c        \
                            listener_tests.c    \
                            lstring_tests.c     \
                            oftc_ircd_tests.c   \
                            opmock.c            \
                            vector_tests.c

AM_CPPFLAGS = -g -O0 @CHECK_CFLAGS@ -I$(top_builddir)/include -I$(top_builddir) \
                -I$(top_builddir)/libuv/include -I$(top_builddir)/json-c
oftc_ircd_tests_LDADD = $(top_builddir)/src/libircd.la @CHECK_LIBS@ \
                $(top_builddir)/json-c/libjson-c.la $(top_builddir)/libuv/libuv.la
