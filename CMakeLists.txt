cmake_minimum_required(VERSION 3.20)
project(SQL2FTP)

set(CMAKE_CXX_STANDARD 17)

set(SQLITE_INCLUDE_DIR    "${CMAKE_SOURCE_DIR}/db_driver/sqlite/include")
set(CURL_INCLUDE_DIR      "${CMAKE_SOURCE_DIR}/third_party/curl/include")
set(DB_DRIVER_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/db_driver/include")

set(CURL_LIB_DIR "${CMAKE_SOURCE_DIR}/third_party/curl/bin")

add_subdirectory(db_driver)

include_directories(${SQLITE_INCLUDE_DIR})
include_directories(${CURL_INCLUDE_DIR})
include_directories(${DB_DRIVER_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${db_driver})

