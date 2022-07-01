#include "ftp_sender.h"

#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <filesystem>

TEST(ftp_sender_test, send_test) {
    bck::ftp::config cfg {
        "127.0.0.1",
        21,
        "karen",
        "something",
        "C:\\FTP"};
    static const std::string bck_file_name{"test.txt"};

    try {
        bck::ftp::sender sender(cfg);

        std::ofstream bck_file(bck_file_name);
        if(!bck_file.is_open()) {
            std::cerr<<"[ERROR]: Cant open backup file: " << bck_file_name<<std::endl;
            ASSERT_TRUE(false);
        }
        bck_file<<"Some data to backup"<<std::endl;
        bck_file.close();

        sender.send_file(bck_file_name, "test_bck.txt");

    } catch(const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        ASSERT_TRUE(false);
    }

    ASSERT_TRUE(std::filesystem::exists(bck_file_name));
    std::filesystem::remove(bck_file_name);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}