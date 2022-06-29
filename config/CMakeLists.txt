cmake_minimum_required(VERSION 3.20)

project(parser)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${DB_DRIVER_INCLUDE_DIR})
include_directories(${FTP_SENDER_INCLUDE_DIR})
include_directories(${SQLITE_INCLUDE_DIR})

file(GLOB PROJECT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
message(STATUS ${PROJECT_SRCS})

add_library(${PROJECT_NAME} STATIC ${PROJECT_SRCS})

set(config ${PROJECT_NAME} CACHE INTERNAL "")

