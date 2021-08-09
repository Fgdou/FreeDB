//
// Created by fgdou on 09/08/2021.
//

#include "FileNotFound.h"

const char *FreeDB::Exception::FileNotFound::what() const noexcept {
    return errorMessage.c_str();
}

FreeDB::Exception::FileNotFound::FileNotFound(const std::string &path)
    : path(path), errorMessage("File not found : " + path)
{
}
