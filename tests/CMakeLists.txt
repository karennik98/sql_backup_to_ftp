cmake_minimum_required(VERSION 3.20)

project(unit_test)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.10.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${DB_DRIVER_INCLUDE_DIR})
include_directories(${FTP_SENDER_INCLUDE_DIR})
include_directories(${SQLITE_INCLUDE_DIR})
include_directories(${APP_INCLUDE_DIR})

add_executable(config_tests config_tests.cpp ftp_sender_tests.cpp)
target_link_libraries(config_tests gtest_main ${application})

add_executable(driver_test db_driver_tests.cpp)
target_link_libraries(driver_test gtest_main ${db_driver} ${application})

add_executable(ftp_sender_test ftp_sender_tests.cpp)
target_link_libraries(ftp_sender_test gtest_main ${ftp_sender} ${application})


