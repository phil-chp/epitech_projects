 /*
** EPITECH PROJECT, 2022
** RType
** File description:
** EventHandler
*/

#ifndef EVENTHANDLER_HPP_
    #define EVENTHANDLER_HPP_

    #include <map>
    #include "GameEngine/PollEvent.hpp"


namespace engine {
    template<typename T>
    class EventHandler {
        public:
            static unsigned int getEvent() {
                return NONE;
            };
    };
}

#endif /* !EVENTHANDLER_HPP_ */
