//
// Created by fgdou on 9/16/21.
//

#ifndef FREEDB_TEST_TOOLS_H
#define FREEDB_TEST_TOOLS_H

#include <vector>

namespace FreeDB {
    class Tools {
    public:
        static int vectorToInt(const std::vector<u_int8_t>& list, int start);
        static std::vector<u_int8_t> intToVector(int n);
    };
}


#endif //FREEDB_TEST_TOOLS_H
