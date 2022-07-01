#include "driver.h"

#include <gtest/gtest.h>
#include <string>
#include <filesystem>

TEST(driver_test, db_connection_test)
{
    bck::sql::config cfg {"test_example.db", "test_bck.txt"};
    try {
        bck::sql::driver db_driver;
        db_driver.connect(cfg);
        ASSERT_EQ(true, db_driver.is_connected());

    } catch(const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        ASSERT_TRUE(false);
    }
    ASSERT_TRUE(std::filesystem::exists(cfg.db_name));
    std::filesystem::remove(cfg.db_name);
}

TEST(driver_test, db_tabel_create)
{
    bck::sql::config cfg {"test_example.db", "test_bck.txt"};
    try {
        bck::sql::driver db_driver;
        db_driver.connect(cfg);
        ASSERT_EQ(true, db_driver.is_connected());
        std::string create = "CREATE TABLE IF NOT EXISTS TEST("
                             "ID INT PRIMARY KEY     NOT NULL);";
        auto code = db_driver.execute(create);
        ASSERT_EQ(0, code);

    } catch(const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        ASSERT_TRUE(false);
    }
    ASSERT_TRUE(std::filesystem::exists(cfg.db_name));
    std::filesystem::remove(cfg.db_name);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}