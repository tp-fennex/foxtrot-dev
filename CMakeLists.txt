cmake_minimum_required(VERSION 3.5.1)
project(foxtrot CXX)
set(EXECUTABLE_NAME "foxtrot")



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

    "${ENGINE_PATH}/include/foxtrot/Application/*.hpp"
    "${ENGINE_PATH}/src/Application/*.cpp"

    "${ENGINE_PATH}/include/foxtrot/Event/*.hpp"
    "${ENGINE_PATH}/src/Event/*.cpp"

    "${ENGINE_PATH}/include/foxtrot/Window/*.hpp"
    "${ENGINE_PATH}/src/Window/*.cpp"

    "${ENGINE_PATH}/include/foxtrot/ECSEngine/*.hpp"
    "${ENGINE_PATH}/src/ECSEngine/*.cpp"

    "${ENGINE_PATH}/include/foxtrot/ECSEngine/utility/*.hpp"
    "${ENGINE_PATH}/src/ECSEngine/utility/*.cpp"
    )
if(ENGINE_SOURCE)
	message("-- Found engine at ${ENGINE_PATH}")
endif()
include_directories("${ENGINE_PATH}/include")



#-------------------------------------------------------------------------------
# target the sandbox game
#-------------------------------------------------------------------------------
set(GAME_PATH "./sandbox")
file(GLOB GAME_SOURCE
    "${GAME_PATH}/include/*.hpp"
    "${GAME_PATH}/src/*.cpp"
)
if(GAME_SOURCE)
    message("-- Found sandbox at ${GAME_PATH}")
endif()



#-------------------------------------------------------------------------------
# target spdlog
#-------------------------------------------------------------------------------
set(SPDLOG_PATH "./foxtrot/vendor/spdlog/include")
include_directories(${SPDLOG_PATH})



set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2.5 REQUIRED COMPONENTS network audio graphics window system)
include_directories(${SFML_INCLUDE_DIR})



add_executable(${EXECUTABLE_NAME} ${ENGINE_SOURCE} ${GAME_SOURCE})

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
