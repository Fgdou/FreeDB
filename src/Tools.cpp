//
// Created by fgdou on 9/16/21.
//

#include "Tools.h"

std::vector<u_int8_t> FreeDB::Tools::intToVector(int n) {
    std::vector<u_int8_t> list(4);
    list[0] = (u_int8_t)(n >> 24);
    list[1] = (u_int8_t)(n >> 16);
    list[2] = (u_int8_t)(n >>  8);
    list[3] = (u_int8_t)(n >>  0);
    return list;
}

int FreeDB::Tools::vectorToInt(const std::vector<u_int8_t> &list, int start) {
    return list[start] << 24 | list[start+1] << 16 | list[start+2] << 8 | list[start+3] << 0;
}
