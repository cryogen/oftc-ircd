lib_LTLIBRARIES = libircd.la
bin_PROGRAMS = ircd
AM_CPPFLAGS = -I$(top_srcdir)/libuv/include -I$(top_srcdir)/json-c/include/json-c -I../include -arch i386 -arch x86_64 -arch x86_64h

libircd_la_SOURCES =  config.c \
                      hash.c \
                      memory.c \
                      murmurhash3.c \
                      serverstate.c

ircd_SOURCES =        main.c

ircd_LDADD = ../libuv/libuv.la ../json-c/libjson-c.la libircd.la
ircd_LDFLAGS = -arch i386 -arch x86_64 -arch x86_64h

libircd_la_LDFLAGS = -arch i386 -arch x86_64 -arch x86_64h
