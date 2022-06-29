cmake_minimum_required(VERSION 3.20)
project(SQL2FTP)

set(CMAKE_CXX_STANDARD 17)

set(SQLITE_INCLUDE_DIR     "${CMAKE_SOURCE_DIR}/db_driver/sqlite/include")
set(DB_DRIVER_INCLUDE_DIR  "${CMAKE_SOURCE_DIR}/db_driver/include")
set(FTP_SENDER_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/ftp_sender/include")
set(CONFIG_INCLUDE_DIR     "${CMAKE_SOURCE_DIR}/config/include")
set(APP_INCLUDE_DIR        "${CMAKE_SOURCE_DIR}/application/include")

add_subdirectory(config)
add_subdirectory(db_driver)
add_subdirectory(ftp_sender)
add_subdirectory(application)

include_directories(${SQLITE_INCLUDE_DIR})
include_directories(${DB_DRIVER_INCLUDE_DIR})
include_directories(${FTP_SENDER_INCLUDE_DIR})
include_directories(${CONFIG_INCLUDE_DIR})
include_directories(${APP_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp )

target_link_libraries(${PROJECT_NAME} ws2_32 wininet ${db_driver} ${ftp_sender} ${config} ${application} )

