lib_LTLIBRARIES = libircd.la
bin_PROGRAMS = ircd
AM_CPPFLAGS =   -I$(top_srcdir)/libuv/include -I$(top_srcdir) \
                -I../include --coverage -g -O0
AM_LDFLAGS = --coverage

libircd_la_SOURCES =    client.c        \
                        config.c        \
                        hash.c          \
                        listener.c      \
                        lstring.c       \
                        memory.c        \
                        module.c        \
                        murmurhash3.c   \
                        network.c       \
                        serverstate.c   \
                        vector.c

ircd_SOURCES =  main.c

ircd_LDADD = ../libuv/libuv.la ../json-c/libjson-c.la libircd.la
