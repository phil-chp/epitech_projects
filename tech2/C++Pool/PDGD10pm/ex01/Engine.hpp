/*
** EPITECH PROJECT, 2022
** PDG-D10-PM (Workspace)
** File description:
** Engine
*/

#pragma once

#include <cstddef>
#include <iostream>
#include <sstream>
#include "BaseComponent.hpp"

class Engine : public BaseComponent {
    public:
        Engine(float power, float x = 0, float y = 0);
        virtual ~Engine();

        void goTorward(float x, float y);
        float distanceTo(float x, float y) const;

        float getX() const;
        float getY() const;

    private:
        float _power;
        float _x;
        float _y;
};
