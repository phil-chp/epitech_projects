/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** NamesPipe
*/

#include "NamedPipe.hpp"

NamedPipe::NamedPipe(std::string const &path)
    : _path(path)
    , _bufferSize(4069)
    , _fd(-1)
{
    if (mkfifo(path.c_str(), 0666) == -1) {
        throw IPCError(errno == EEXIST
            ? "fifo file " + this->_path + ", already exists."
            : "couldn't create fifo file.");
    }
    if ((this->_fd = open(path.c_str(), O_RDWR | O_APPEND)) == -1) {
        throw IPCError("couldn't open fifo file.");
    }
}

NamedPipe::NamedPipe(size_t std)
    : _path("STREAM(" + std::to_string(std) + ")")
    , _bufferSize(4069)
    , _fd(std)
{}

NamedPipe::~NamedPipe()  {
    if (this->_fd > 0) {
        close(this->_fd);
        if (unlink(_path.c_str()) == -1) {
            IPCError("couldn't unlink fifo file.");
        }
    }
}

//* -------------------------------- Public -------------------------------- *//

void NamedPipe::write(std::string const &str) {
    int fd = (this->_fd == 0) ? 1 : this->_fd;
    if (::write(fd, &str, str.size()) == -1) {
        throw IPCError("couldn't write to fifo file.");
    }
    if (::write(fd, "\n", 1) == -1) {
        throw IPCError("couldn't write to fifo file.");
    }
}

// template <typename T> NamedPipe &NamedPipe::operator<<(T const &data)
// {
//     this->write(std::to_string(data));
//     return (*this);
// };

// template <typename T>
// T NamedPipe::read() {
//     T &tmp;
//     if (this->_fd == -1 || ::read(_fd, &tmp, sizeof(tmp)) == -1) {
//         this->_throw("couldn't read from fifo file.");
//     }
//     return (tmp);
// }

// template <typename T> NamedPipe &NamedPipe::operator>>(T &data)
// {
//     data = this->read<T>();
//     return (*this);
// };

std::string NamedPipe::getBuffer() {
    if (this->_data.size() == 0) {
        return ("");
    }
    return (*this->_data.erase(this->_data.begin()));
}

void NamedPipe::setBuffer(void)
{
    this->_buffer += this->_readBuffer();
    size_t pos = 0;
    size_t nb = std::count(this->_buffer.begin(), this->_buffer.end(), '\n');

    while (pos < this->_buffer.size()) {
        std::string tmp(
            this->_buffer.substr(pos, this->_buffer.find('\n', pos + 1))
        );
        pos += tmp.size() + 1;
        this->_data.push_back(tmp);
    }
    if (this->_data.size() == nb - 1) {
        this->_buffer = *this->_data.erase(this->_data.end() - 1);
    } else {
        this->_buffer = "";
    }
}

std::vector<NamedPipe> NamedPipe::select(std::vector<NamedPipe> fdVec) {
    fd_set rfds = NamedPipe::getFdSet(fdVec);
    std::vector<NamedPipe> active;

    int ret = ::select(FD_SETSIZE, &rfds, NULL, NULL, NULL);
    if (ret == -1) {
        throw Errors("error (errno: " + std::to_string(errno) + ")", "Select");
    } else if (ret > 0) {
        std::copy_if(fdVec.begin(), fdVec.end(),
            std::back_inserter(active),
            [&rfds](NamedPipe const &np) -> bool {
                return (FD_ISSET(np.getFd(), &rfds));
            }
        );
    }
    return (active);
}

fd_set NamedPipe::getFdSet(std::vector<NamedPipe> fdVec) {
    fd_set rfds;

    FD_ZERO(&rfds);
    for (NamedPipe const &np : fdVec) {
        FD_SET(np.getFd(), &rfds);
    }
    return (rfds);
}

//* -------------------------------- Private ------------------------------- *//

std::string NamedPipe::_readBuffer(void) {
    char buffer[4096];
    int len;

    if ((len = ::read(this->_fd, buffer, 4096)) == -1) {
        throw IPCError("couldn't read from fifo file.");
    }
    buffer[len] = '\0';
    return (std::string(buffer));
}
