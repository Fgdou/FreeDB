//
// Created by fgdou on 09/08/2021.
//

#include <gtest/gtest.h>
#include "File.h"

TEST(File, write){
    std::string path = "writes.txt";
    std::string word = "Salut les copains";
    std::string word2 = "Hello world\nEverything is fine";

    if(FreeDB::File::exist(path))
        FreeDB::File::remove(path);

    ASSERT_FALSE(FreeDB::File::exist(path));
    FreeDB::File::write(word, path);
    ASSERT_TRUE(FreeDB::File::exist(path));

    auto content = FreeDB::File::readAll(path);
    ASSERT_EQ(1, content.size());
    ASSERT_EQ(word, content[0]);


    FreeDB::File::write(word2, path);
    ASSERT_TRUE(FreeDB::File::exist(path));

    auto content2 = FreeDB::File::readAll(path);
    ASSERT_EQ(2, content2.size());
    ASSERT_EQ("Hello world", content2[0]);
    ASSERT_EQ("Everything is fine", content2[1]);

    FreeDB::File::remove(path);
    ASSERT_FALSE(FreeDB::File::exist(path));
}