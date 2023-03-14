/*
** EPITECH PROJECT, 2022
** Arcade (Workspace)
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
# define CLOCK_HPP_

# include <chrono>
#include <iostream>

namespace arc
{

# define _FPS       60.0F
# define _INTERVAL  (20.0F / _FPS)

    class Clock
    {
        typedef std::chrono::high_resolution_clock HDCLock;
        typedef std::chrono::high_resolution_clock::time_point TimePoint;

        public:
            Clock() : _time(HDCLock::now()) {};
            ~Clock() {};

            std::chrono::duration<double> restart()
            {
                TimePoint now(HDCLock::now());
                std::chrono::duration<double> elapsed(now - this->_time);

                this->_time = now;
                return (elapsed);
            };

            std::chrono::duration<double> getElapsed()
            {
                TimePoint now(HDCLock::now());
                std::chrono::duration<double> elapsed(now - this->_time);

                return (elapsed);
            };

            bool isCycleDone(bool restart = false)
            {
                if (this->getElapsed().count() >= _INTERVAL) {
                    if (restart) this->restart();
                    return (true);
                }
                return (false);
            };

        private:
            TimePoint _time;
    };
}
#endif /* !CLOCK_HPP_ */
