//
// Created by fgdou on 09/08/2021.
//

#ifndef FREEDB_TABLE_H
#define FREEDB_TABLE_H

#include <string>
#include <map>
#include "Elements/Element.h"

namespace FreeDB {
    class Table {
    public:
        Table(const Table& copy) = delete;

        static Table open(const std::string& name);
        static Table create(const std::string& name);

        void add(Element& e);
        Element& get(int id);

        void clear();
        void remove();

        ~Table();
    private:

        Table(const std::string name, bool exist);

        std::string url;
        std::string name;

        std::map<int, Element*> map;
    };
}


#endif //FREEDB_TABLE_H
