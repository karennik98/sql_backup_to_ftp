cmake_minimum_required(VERSION 3.20)

project(sqlite3)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB PROJECT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SRCS})

set(sqlite3 ${PROJECT_NAME} CACHE INTERNAL "")

