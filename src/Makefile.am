bin_PROGRAMS=ircd
AM_CPPFLAGS = -I$(top_srcdir)/libuv/include -I$(top_srcdir)/json-c/include/json-c -I../include

ircd_SOURCES= config.c \
              hash.c \
              main.c \
              memory.c \
              murmurhash3.c \
              serverstate.c

ircd_LDADD = ../libuv/libuv.la ../json-c/libjson-c.la
