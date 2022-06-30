#include "driver.h"

#include <gtest/gtest.h>
#include <string>

TEST(driver_test, db_connection_test)
{
    try {

    } catch(const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        ASSERT_TRUE(false);
    }
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}