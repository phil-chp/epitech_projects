/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** SFMLBuilder
*/

#ifndef SFMLBUILDER_HPP_
#define SFMLBUILDER_HPP_

#include "Configurable.hpp"
#include "SFMLDashboard.hpp"
#include <SFML/Graphics.hpp>

typedef struct SFMLBuilderConfig {

} SFMLBuilderConfig;

class SFMLBuilder
    : public Configurable<SFMLBuilderConfig>
{
    private:
        SFMLDashboard *_dashboard;

    public:
        SFMLBuilder(SFMLDashboard *dashboard);
        ~SFMLBuilder();

        void CreateWindow();
        void CreateElements();

        const int WIDTH;
        const int HEIGHT;
        const int PIXEL;
        const float FPS;

        sf::Event event;

        sf::RenderWindow *window;
        sf::CircleShape *circle;

};

#endif /* !SFMLBUILDER_HPP_ */
