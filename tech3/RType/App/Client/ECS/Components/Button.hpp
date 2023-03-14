/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

    #include "Utils/Vector2.hpp"
    #include "ECS/Entity.hpp"


namespace ecs {

    struct Button {
        public:

            Entity (*click)(Entity);  //clic function
            void (*hover)(Entity);    //hover function
            void (*resetHover)(Entity);    //hover function
            Entity next;        //circular button list
            bool isHover;
            bool isClic;
            bool isEsc;         //for ESCAPE  maccro
            Entity prev;        //circular button list
            bool dead;
            unsigned int listID;
        // private:

    };


};

#endif /* !BUTTON_HPP_ */
