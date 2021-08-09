//
// Created by fgdou on 09/08/2021.
//

#include <string>
#include "FileNotOpened.h"

const char *FreeDB::Exception::FileNotOpened::what() const noexcept {
    return errorMessage.c_str();
}

FreeDB::Exception::FileNotOpened::FileNotOpened(const std::string &path)
        : path(path), errorMessage("File not opened : " + path)
{
}
