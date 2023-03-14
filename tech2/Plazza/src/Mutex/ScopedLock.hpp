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
        explicit ScopedLock(std::shared_ptr<std::mutex> &mutex, bool trylock = false);
        ~ScopedLock();

    private:
        std::shared_ptr<std::mutex> _mutex;
};

#endif /* !SCOPEDLOCK_HPP_ */
