/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** IDrawale
*/

#ifndef IDRAWALE_HPP_
#define IDRAWALE_HPP_

// TODO: Look into "Mixin classes" and the "CRTP" for a better approach
// TODO: to draw instead of IDrawable
class IDrawable {
    public:
        virtual void draw() const = 0;
};

#endif /* !IDRAWALE_HPP_ */
