bin_PROGRAMS=ircd
AM_CPPFLAGS = -I$(top_srcdir)/libuv/include -I$(top_srcdir)/json-c/include/json-c -I../include

ircd_SOURCES= main.c \
              config.c \
              serverstate.c

ircd_LDADD = ../libuv/libuv.la ../json-c/libjson-c.la
