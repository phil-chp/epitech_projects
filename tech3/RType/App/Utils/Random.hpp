/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Random
*/

#ifndef RANDOM_HPP_
#define RANDOM_HPP_

        #include <random>
        #include <exception>
        #include <string>

namespace game {
class Random {
    public:
        static float getRandomValue(float min, float max) {
            return min + (rand() / (float)RAND_MAX) * (max - min);
        }

        static int getRandomIntValue(int min, int max) {
            // return min + (rand() / (int)RAND_MAX) * (max - min);
            return (rand()%(max-min + 1) + min);
        }
};
};

#endif /* !RANDOM_HPP_ */
