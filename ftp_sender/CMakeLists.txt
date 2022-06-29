cmake_minimum_required(VERSION 3.20)

project(ftp_sender)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB PROJECT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SRCS})

target_link_libraries(${PROJECT_NAME} wininet ws2_32)

set(ftp_sender ${PROJECT_NAME} CACHE INTERNAL "")

