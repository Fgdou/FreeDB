//
// Created by fgdou on 09/08/2021.
//

#ifndef FREEDB_FILE_H
#define FREEDB_FILE_H

#include <string>
#include <vector>

namespace FreeDB {
    class File {
    public:
        static std::string getBasicPath();
        static bool exist(const std::string& path);

        static std::vector<std::string> readAll(const std::string& path);
        static void write(const std::string& str, const std::string& path);

        static void remove(const std::string& path);
    };
}


#endif //FREEDB_FILE_H
