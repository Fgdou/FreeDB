//
// Created by fgdou on 09/08/2021.
//

#ifndef FREEDB_FILENOTFOUND_H
#define FREEDB_FILENOTFOUND_H

#include <exception>
#include <string>

namespace FreeDB {
    namespace Exception {
        class FileNotFound : public std::exception {
        public:
            explicit FileNotFound(const std::string& path);

            const char * what() const noexcept override;

        private:
            const std::string path;
            const std::string errorMessage;
        };
    }
}

#endif //FREEDB_FILENOTFOUND_H
