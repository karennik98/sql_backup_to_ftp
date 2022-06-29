cmake_minimum_required(VERSION 3.20)

project(db_driver)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sqlite/include)

add_subdirectory(sqlite)

file(GLOB PROJECT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SRCS})

target_link_libraries(${PROJECT_NAME} ${sqlite3})

set(db_driver ${PROJECT_NAME} CACHE INTERNAL "")

