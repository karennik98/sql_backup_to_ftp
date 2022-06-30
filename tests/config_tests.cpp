#include "config.h"

#include <gtest/gtest.h>
#include <string>

static const std::string test_config_file{R"(C:\Users\karen\CLionProjects\SQL2FTP\tests\assets\test_config.json)"};

TEST(config_test, db_config_parse_test)
{
    try {
        bck::json::config_parser parser{};
        parser.parse(test_config_file);
        auto db_cfg = parser.get_db_config();
        ASSERT_NE("", db_cfg.db_name);
        ASSERT_NE("", db_cfg.db_backup);
    } catch(const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        ASSERT_TRUE(false);
    }
}

TEST(config_test, ftp_config_parse_test)
{
    try {
        bck::json::config_parser parser{};
        parser.parse(test_config_file);
        auto ftp_cfg = parser.get_ftp_config();
        ASSERT_NE("", ftp_cfg.upload_folder);
        ASSERT_NE("", ftp_cfg.password);
        ASSERT_NE("", ftp_cfg.username);
    } catch(const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        ASSERT_TRUE(false);
    }
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}