//
// Created by fgdou on 09/08/2021.
//

#ifndef FREEDB_TEST_FILENOTOPENED_H
#define FREEDB_TEST_FILENOTOPENED_H


namespace FreeDB {
    namespace Exception {
        class FileNotOpened : public std::exception {
        public:
            explicit FileNotOpened(const std::string& path);

            const char * what() const noexcept override;

        private:
            const std::string path;
            const std::string errorMessage;
        };
    }
}
#endif //FREEDB_TEST_FILENOTOPENED_H
