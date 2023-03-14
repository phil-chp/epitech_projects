/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
    #define ANIMATION_HPP_


    #include "Utils/Vector2.hpp"
    #include <map>
    #include <memory>

namespace ecs {
    template <typename T, typename K>
    struct Animation {
        std::map<int, unsigned int> max;
        std::map<int, K> container;
        std::pair<int, unsigned int> current;
        std::pair<int, unsigned int> setTo;
        bool toSet;
        float delay;
        float actualDelay;
        bool fix;

        Animation() = default;
        // Animation(const Animation<T, K> &othr);
        void advance();
        void set(int n, unsigned int k = 0);
    };
}

#endif /* !ANIMATION_HPP_ */