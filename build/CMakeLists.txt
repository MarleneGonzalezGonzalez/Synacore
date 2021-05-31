cmake_minimum_required(VERSION 3.16)
project(fx_converter)

set(CMAKE_BUILD_TYPE Debug)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(../include)

file(GLOB SOURCES "../src/*.cpp")

add_executable(main.exe ${SOURCES})

target_link_libraries(main.exe PRIVATE Threads::Threads)
