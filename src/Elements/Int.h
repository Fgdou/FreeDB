//
// Created by fgdou on 09/08/2021.
//

#ifndef FREEDB_INT_H
#define FREEDB_INT_H

#include "Element.h"

namespace FreeDB {
    class Int : public Element {
    public:
        Int();
        explicit Int(int n);
        Int(Int& copy) = default;
        Int(Int&& move) = default;
        Int(const std::vector<u_int8_t> list, int start);

        ~Int() override;

        int getValue() const;
        void setValue(int n);

        std::vector<u_int8_t> getByte() override;
    private:
        int n;
    };
}


#endif //FREEDB_INT_H
