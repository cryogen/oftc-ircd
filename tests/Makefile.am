TESTS = client_tests    \
        command_tests   \
        config_tests    \
        hash_tests      \
        lstring_tests   \
        vector_tests    \
        network_tests   \
        module_tests    \
        server_tests

check_PROGRAMS =    client_tests    \
                    command_tests   \
                    config_tests    \
                    hash_tests      \
                    lstring_tests   \
                    vector_tests    \
                    network_tests   \
                    module_tests    \
                    server_tests

AM_LDFLAGS = --coverage

client_tests_LDADD =    memory_stub.o           \
                        vector_stub.o           \
                        hash_stub.o             \
                        uv_stub.o               \
                        opmock.o                \
                        ../src/serverstate.o    \
                        ../src/network.o        \
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

hash_tests_LDADD =      opmock.o                \
                        memory_stub.o           \
                        murmurhash3_stub.o      \
                        ../src/hash.o

lstring_tests_LDADD =   opmock.o                \
                        ../src/lstring.o

vector_tests_LDADD  =   opmock.o                \
                        memory_stub.o           \
                        ../src/vector.o

network_tests_LDADD =   opmock.o                \
                        uv_stub.o               \
                        ../src/network.o

module_tests_LDADD  =   opmock.o                \
                        config_stub.o           \
                        vector_stub.o           \
                        serverstate_stub.o      \
                        memory_stub.o           \
                        uv_stub.o               \
                        json_object_stub.o      \
                        ../src/module.o

command_tests_LDADD =   opmock.o                \
                        memory_stub.o           \
                        hash_stub.o             \
                        ../src/command.o

server_tests_LDADD =    opmock.o                \
                        client_stub.o           \
                        config_stub.o           \
                        json_object_stub.o      \
                        ../src/server.o

AM_CPPFLAGS = -g -O0 -I../include -I../libuv/include -I.. -I../json-c
