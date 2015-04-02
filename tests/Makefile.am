TESTS = client_tests    \
        command_tests   \
        config_tests    \
        hash_tests      \
        lstring_tests   \
        vector_tests    \
        network_tests   \
        module_tests    \
        server_tests    \
        buffer_tests

check_PROGRAMS =    client_tests    \
                    command_tests   \
                    config_tests    \
                    hash_tests      \
                    lstring_tests   \
                    vector_tests    \
                    network_tests   \
                    module_tests    \
                    server_tests    \
                    buffer_tests

AM_LDFLAGS = --coverage

client_tests_SOURCES =  client_tests.c          \
                        memory_stub.c           \
                        vector_stub.c           \
                        hash_stub.c             \
                        uv_stub.c               \
                        server_stub.c           \
                        buffer_stub.c           \
                        opmock.c                \
                        ../src/serverstate.c    \
                        ../src/network.c        \
                        ../src/client.c

config_tests_SOURCES =  config_tests.c          \
                        vector_stub.c           \
                        hash_stub.c             \
                        uv_stub.c               \
                        json_object_stub.c      \
                        json_tokener_stub.c     \
                        serverstate_stub.c      \
                        memory_stub.c           \
                        opmock.c                \
                        ../src/config.c

hash_tests_SOURCES =    hash_tests.c            \
                        opmock.c                \
                        memory_stub.c           \
                        murmurhash3_stub.c      \
                        ../src/hash.c

lstring_tests_SOURCES = lstring_tests.c         \
                        opmock.c                \
                        ../src/lstring.c

vector_tests_SOURCES  = vector_tests.c          \
                        opmock.c                \
                        memory_stub.c           \
                        ../src/vector.c

network_tests_SOURCES = network_tests.c         \
                        opmock.c                \
                        uv_stub.c               \
                        ../src/network.c

module_tests_SOURCES  = module_tests.c          \
                        opmock.c                \
                        config_stub.c           \
                        vector_stub.c           \
                        serverstate_stub.c      \
                        memory_stub.c           \
                        uv_stub.c               \
                        json_object_stub.c      \
                        ../src/module.c

command_tests_SOURCES = command_tests.c         \
                        opmock.c                \
                        memory_stub.c           \
                        hash_stub.c             \
                        ../src/command.c

server_tests_SOURCES =  server_tests.c          \
                        opmock.c                \
                        client_stub.c           \
                        config_stub.c           \
                        json_object_stub.c      \
                        ../src/server.c

buffer_tests_SOURCES =  buffer_tests.c          \
                        opmock.c                \
                        memory_stub.c           \
                        ../src/buffer.c         

AM_CPPFLAGS = -g -O0 -I../include -I../libuv/include -I.. -I../json-c --coverage
