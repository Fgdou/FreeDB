//
// Created by fgdou on 09/08/2021.
//

#include "Element.h"
#include "Int.h"
#include "../Tools.h"

FreeDB::Element::Element(Type type)
    : parent(nullptr), type(type)
{

}

FreeDB::Element *FreeDB::Element::getParent() const {
    return parent;
}

void FreeDB::Element::setParent(FreeDB::Element *parent) {
    this->parent = parent;
}

FreeDB::Element::Type FreeDB::Element::getType() const {
    return type;
}

std::shared_ptr<FreeDB::Element> FreeDB::Element::parse(const std::vector<u_int8_t> list, int start) {
    Type t = (Type)list[start+0];
    int length = Tools::vectorToInt(list, start+1);

    std::shared_ptr<FreeDB::Element> pt;

    switch(t){
        case Type::INT:
            pt = std::make_shared<Int>(list, start+5);
            break;
        default: ;
    }

    return pt;
}

FreeDB::Element::~Element() {

}
