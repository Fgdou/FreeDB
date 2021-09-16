//
// Created by fgdou on 9/16/21.
//

#include <gtest/gtest.h>
#include "Tools.h"

TEST(Tools, intToArray){
    std::vector<u_int8_t> expected1{0x00, 0x00, 0x00, 0x00};
    std::vector<u_int8_t> expected2{0x00, 0x00, 0x00, 0x01};
    std::vector<u_int8_t> expected3{0x00, 0x00, 0x01, 0x00};
    std::vector<u_int8_t> expected4{0xFF, 0xFF, 0xFF, 0xFF};

    ASSERT_EQ(expected1, FreeDB::Tools::intToVector(0));
    ASSERT_EQ(expected2, FreeDB::Tools::intToVector(1));
    ASSERT_EQ(expected3, FreeDB::Tools::intToVector(0x0100));
    ASSERT_EQ(expected4, FreeDB::Tools::intToVector(-1));
}
TEST(Tools, arrayToInt){
    ASSERT_EQ(0, FreeDB::Tools::vectorToInt({0x00, 0x00, 0x00, 0x00}, 0));
    ASSERT_EQ(1, FreeDB::Tools::vectorToInt({0x00, 0x00, 0x00, 0x01}, 0));
    ASSERT_EQ(0x0100, FreeDB::Tools::vectorToInt({0x00, 0x00, 0x01, 0x00}, 0));
    ASSERT_EQ(-1, FreeDB::Tools::vectorToInt({0xFF, 0xFF, 0xFF, 0xFF}, 0));
}
TEST(Tools, intToArrayToInt){
    srand(time(nullptr));
    for(int i=0; i<100; i++){
        int n = rand();
        auto list = FreeDB::Tools::intToVector(n);
        int n2 = FreeDB::Tools::vectorToInt(list, 0);

        ASSERT_EQ(n, n2);
    }
}