cmake_minimum_required(VERSION 3.10)
project(server)

find_package(Boost COMPONENTS system asio threads)
find_package(Threads)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(server main.cpp Client.cpp Server.cpp Session.cpp)

TARGET_LINK_LIBRARIES(server ${Boost_LIBRARIES})
