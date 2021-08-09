//
// Created by fgdou on 09/08/2021.
//

#include <fstream>
#include "Exceptions/FileNotFound.h"
#include "Exceptions/FileNotOpened.h"
#include "File.h"

std::string FreeDB::File::getBasicPath() {
    std::string path = std::getenv("FREEDB_PATH");
    if(path[path.length()-1] != '/')
        path += '/';
    return path;
}

bool FreeDB::File::exist(const std::string& path) {
    std::ifstream stream(path.c_str());
    return stream.good();
}
std::vector<std::string> FreeDB::File::readAll(const std::string& path) {

    if(!exist(path))
        throw Exception::FileNotFound(path);

    std::fstream fdesc;
    fdesc.open(path);
    if(!fdesc.is_open())
        throw Exception::FileNotOpened(path);
    std::vector<std::string> vec;

    std::string s;
    while(std::getline(fdesc, s))
        vec.push_back(s);
    fdesc.close();

    return vec;
}

void FreeDB::File::write(const std::string &str, const std::string& path) {
    std::fstream fdesc;
    fdesc.open(path, std::fstream::out);
    if(!fdesc.is_open())
        throw Exception::FileNotOpened(path);
    fdesc << str << '\n';
    fdesc.close();
}

void FreeDB::File::remove(const std::string &path) {
    if(!exist(path))
        throw Exception::FileNotFound(path);
    std::remove(path.c_str());
}
