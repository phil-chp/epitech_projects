/*
** EPITECH PROJECT, 2022
** plazza-boostrap
** File description:
** ScopedLock
*/

#ifndef SCOPEDLOCK_HPP_
    #define SCOPEDLOCK_HPP_

    #include <memory>
    #include <mutex>

class ScopedLock {
    public:
        explicit ScopedLock(std::mutex &mutex, bool trylock = false)
            : _mutex(mutex)
        {
            if (trylock)
                this->_mutex.try_lock();
            else
                this->_mutex.lock();
        }
        ~ScopedLock() {
            this->_mutex.unlock();
        }

    private:
        std::mutex& _mutex;
};

#endif /* !SCOPEDLOCK_HPP_ */
