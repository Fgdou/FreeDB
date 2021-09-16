//
// Created by fgdou on 9/16/21.
//
#include <gtest/gtest.h>
#include "Elements/Int.h"

TEST(Int, Creation){
    FreeDB::Int i1;

    ASSERT_EQ(0, i1.getValue());

    i1.setValue(1);
    ASSERT_EQ(1, i1.getValue());

    FreeDB::Int i2({0x00, 0x00, 0x00, 0x08}, 0);
    ASSERT_EQ(8, i2.getValue());
}
TEST(Int, Element){
    FreeDB::Element* e = new FreeDB::Int(9);

    ASSERT_EQ(nullptr, e->getParent());
    ASSERT_EQ(FreeDB::Element::Type::INT, e->getType());
    ASSERT_EQ(9, ((FreeDB::Int*)e)->getValue());

    std::vector<u_int8_t> expected{0x00, 0x00, 0x00, 0x09};
    ASSERT_EQ(expected, e->getByte());
}
TEST(Int, CreatingElement){
    auto e = FreeDB::Element::parse({(u_int8_t)FreeDB::Element::Type::INT, 0,0,0,0, 0xFF, 0xFF, 0xFF, 0xFE}, 0);
    ASSERT_EQ(FreeDB::Element::Type::INT, e->getType());
    auto i = std::dynamic_pointer_cast<FreeDB::Int>(e);
    ASSERT_EQ(-2, i->getValue());
}