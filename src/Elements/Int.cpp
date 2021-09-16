//
// Created by fgdou on 09/08/2021.
//

#include "Int.h"
#include "../Tools.h"

FreeDB::Int::Int()
    : Element(Element::Type::INT), n(0)
{

}

FreeDB::Int::Int(int n)
    : Element(Element::Type::INT), n(n)
{

}

int FreeDB::Int::getValue() const {
    return n;
}

void FreeDB::Int::setValue(int n) {
    this->n = n;
}

std::vector<u_int8_t> FreeDB::Int::getByte() {
    return Tools::intToVector(n);
}

FreeDB::Int::Int(const std::vector<u_int8_t> list, int start)
    : Element(Element::Type::INT)
{
    n = Tools::vectorToInt(list, start);
}

FreeDB::Int::~Int() {

}
