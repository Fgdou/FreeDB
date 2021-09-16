//
// Created by fgdou on 09/08/2021.
//

#ifndef FREEDB_ELEMENT_H
#define FREEDB_ELEMENT_H

#include <vector>
#include <memory>

namespace FreeDB {
    class Element {
    public:
        enum class Type{
            ARRAY,
            DOUBLE,
            INT,
            OBJECT,
            STR,
            CNT
        };

        int getId() const;
        Element *getParent() const;
        void setParent(Element *parent);
        Type getType() const;

        virtual ~Element();
        virtual std::vector<u_int8_t> getByte() = 0;

        static std::shared_ptr<Element> parse(const std::vector<u_int8_t> list, int start);
    protected:
        Element(Type type);
    private:
        const Type type;
        Element* parent;
    };
}


#endif //FREEDB_ELEMENT_H
