lib_LTLIBRARIES = libircd.la
bin_PROGRAMS = ircd
AM_CPPFLAGS =   -I$(top_srcdir)/libuv/include -I$(top_srcdir) \
                -I../include -I$(top_srcdir)/libtls/include

libircd_la_SOURCES =    buffer.c        \
                        client.c        \
                        command.c       \
                        config.c        \
                        connection.c    \
                        hash.c          \
                        list.c          \
                        listener.c      \
                        lstring.c       \
                        memory.c        \
                        module.c        \
                        murmurhash3.c   \
                        network.c       \
                        parser.c        \
                        server.c        \
                        serverstate.c   \
                        vector.c

ircd_SOURCES =  main.c

ircd_LDADD = ../libuv/libuv.la ../json-c/libjson-c.la libircd.la ../libtls/tls/libtls.la

clean-local:
		rm -rf *.gcda
		rm -rf *.gcno 
