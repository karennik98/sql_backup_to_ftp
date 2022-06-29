cmake_minimum_required(VERSION 3.20)

project(application)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${DB_DRIVER_INCLUDE_DIR})
include_directories(${FTP_SENDER_INCLUDE_DIR})
include_directories(${SQLITE_INCLUDE_DIR})
include_directories(${CONFIG_INCLUDE_DIR})

file(GLOB PROJECT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SRCS})

target_link_libraries(${PROJECT_NAME} ${db_driver} ${ftp_sender} ${config} ws2_32)

set(application ${PROJECT_NAME} CACHE INTERNAL "")

