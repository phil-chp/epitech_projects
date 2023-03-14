/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** NamedPipe
*/

#ifndef NAMEDPIPE_HPP_
    #define NAMEDPIPE_HPP_

    #include "Errors/Errors.hpp"
    #include <iostream>
    #include <unistd.h>
    #include <algorithm>
    #include <vector>
    #include <sys/select.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

class NamedPipe {
    public:
        explicit NamedPipe(std::string const &path);
        explicit NamedPipe(size_t std);
        ~NamedPipe();

        int getFd() const {
            return (this->_fd);
        };

        std::string const &getPath() const {
            return (this->_path);
        };

        //* ------------ Write/Read -------------- *//
        void write(std::string const &str);
        // template <typename T> NamedPipe &operator<<(T const &data);

        // template <typename T> T read();
        // template <typename T> NamedPipe &operator>>(T &data);

        //* --------------- Buffer --------------- *//
        bool operator==(std::string const &path) const {
            return (this->_path == path);
        }
        bool operator!=(std::string const &path) const {
            return (this->_path != path);
        }
        bool operator==(int fd) const {
            return (this->_fd == fd);
        }
        bool operator!=(int fd) const {
            return (this->_fd != fd);
        }

        std::string getBuffer();
        void setBuffer(void);

        //* -------------------------- Select ------------------------------ *//
        static std::vector<NamedPipe> select(std::vector<NamedPipe> fdVec);
        static fd_set getFdSet(std::vector<NamedPipe> fdVec);
    private:
        std::string _readBuffer(void);

        std::string _path;
        std::string _buffer;
        std::vector<std::string> _data;
        size_t _bufferSize;
        int _fd;
};

#endif /* !NAMEDPIPE_HPP_ */
