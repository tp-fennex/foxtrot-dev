cmake_minimum_required(VERSION 3.5.1)
project(foxtrot CXX)
set(EXECUTABLE_NAME "foxtrot")
set(EXECUTABLE_NAME_SERVER "foxtrot_server")



#-------------------------------------------------------------------------------
# Compiler config
#-------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-Wconversion")
    add_compile_options("-pedantic")
    add_compile_options("-Wfatal-errors")
endif()



#-------------------------------------------------------------------------------
# target engine
#-------------------------------------------------------------------------------
set(ENGINE_PATH "./foxtrot")
file(GLOB ENGINE_SOURCE
    "${ENGINE_PATH}/include/foxtrot/*.hpp"
    "${ENGINE_PATH}/src/*.cpp"

    "${ENGINE_PATH}/include/foxtrot/Event/*.hpp"
    "${ENGINE_PATH}/src/Event/*.cpp"

    # Event proto files
    "${ENGINE_PATH}/include/foxtrot/Event/proto/*.h"
    "${ENGINE_PATH}/include/foxtrot/Event/proto/*.cc"

    "${ENGINE_PATH}/include/foxtrot/Event/workers/*.hpp"
    "${ENGINE_PATH}/src/Event/workers/*.cpp"

    "${ENGINE_PATH}/include/foxtrot/Application/*.hpp"
    "${ENGINE_PATH}/src/Application/*cpp"

    "${ENGINE_PATH}/include/foxtrot/Window/*.hpp"
    "${ENGINE_PATH}/src/Window/*cpp"
    )
if(ENGINE_SOURCE)
    message("-- Found engine at ${ENGINE_PATH}")
endif()
include_directories("${ENGINE_PATH}/include")



#-------------------------------------------------------------------------------
# target engine server
#-------------------------------------------------------------------------------
file(GLOB ENGINE_SERVER_SOURCE
        "${ENGINE_PATH}/include/foxtrot/Server/*.hpp"
        "${ENGINE_PATH}/src/Server/*.cpp"

        "${ENGINE_PATH}/include/foxtrot/Client/*.hpp"
        "${ENGINE_PATH}/src/Client/*.cpp"

        "${ENGINE_PATH}/include/foxtrot/Session/*.hpp"
        "${ENGINE_PATH}/src/Session/*.cpp"

        "${ENGINE_PATH}/include/foxtrot/Event/Event.hpp"
        "${ENGINE_PATH}/src/Event/Event.cpp"

        "${ENGINE_PATH}/include/foxtrot/Event/proto/*.h"
        "${ENGINE_PATH}/include/foxtrot/Event/proto/*.cc"
        )



#-------------------------------------------------------------------------------
# target google protobuf
#-------------------------------------------------------------------------------
find_package(Protobuf REQUIRED)
set(PROTO_FILES ${ENGINE_PATH}/include/foxtrot/Event/proto/event.proto)
include_directories(${Protobuf_INCLUDE_DIRS})
message("Generating protocol buffers headers and source files")
execute_process(
    COMMAND bash -c "./generate.sh"
    WORKING_DIRECTORY "../foxtrot/include/foxtrot/Event/proto"
    OUTPUT_VARIABLE PROTO_GEN_OUT
)
message(ProtoPath ${PROTO_GEN_OUT})



#-------------------------------------------------------------------------------
# target boost
#-------------------------------------------------------------------------------
find_package(Boost COMPONENTS asio system)
include_directories(${Boost_INCLUDE_DIRS})



#-------------------------------------------------------------------------------
# target SFML
#-------------------------------------------------------------------------------
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5 REQUIRED COMPONENTS network audio graphics window system)
include_directories(${SFML_INCLUDE_DIR})



#-------------------------------------------------------------------------------
# target spdlog
#-------------------------------------------------------------------------------
set(SPDLOG_PATH "./foxtrot/vendor/spdlog/include")
include_directories(${SPDLOG_PATH})



#-------------------------------------------------------------------------------
# target EnTT
#-------------------------------------------------------------------------------
set(ENTT_PATH "./foxtrot/vendor/entt/src")
include_directories(${ENTT_PATH})



#-------------------------------------------------------------------------------
# target the sandbox game
#-------------------------------------------------------------------------------
set(GAME_PATH "./sandbox")
file(GLOB GAME_SOURCE
    "${GAME_PATH}/client/*.cpp"
)
if(GAME_SOURCE)
    message("-- Found sandbox at ${GAME_PATH}")
endif()

add_executable(${EXECUTABLE_NAME} ${ENGINE_SOURCE} ${GAME_SOURCE})

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(${EXECUTABLE_NAME} ${Protobuf_LIBRARIES})
target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})



file(GLOB GAME_SERVER_SOURCE
    "${GAME_PATH}/server/*.cpp"
)

add_executable(${EXECUTABLE_NAME_SERVER} ${ENGINE_SERVER_SOURCE} ${GAME_SERVER_SOURCE})

target_link_libraries(${EXECUTABLE_NAME_SERVER} ${Protobuf_LIBRARIES})
target_link_libraries(${EXECUTABLE_NAME_SERVER} ${Boost_LIBRARIES})
