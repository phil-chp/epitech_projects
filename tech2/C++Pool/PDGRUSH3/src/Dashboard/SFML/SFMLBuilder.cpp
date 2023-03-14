/*
** EPITECH PROJECT, 2022
** C POOL, rush-03-myGKrellm
** authored by:
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
**      Vitali DROUJKO <vitali.droujko@epitech.eu>
**      Mateo DEROCHE <mateo.deroche.epitech.eu>
** File description:
** TODO
*/

#include "SFMLBuilder.hpp"

SFMLBuilder::SFMLBuilder(SFMLDashboard *dashboard)
    : _dashboard(dashboard)
    , WIDTH(512)
    , HEIGHT(1024)
    , PIXEL(32)
    , FPS(60.0f)
{
    CreateWindow();
    CreateElements();
}

SFMLBuilder::~SFMLBuilder() {}

void SFMLBuilder::CreateWindow()
{
    sf::VideoMode mode = sf::VideoMode(WIDTH, HEIGHT, PIXEL);
    window = new sf::RenderWindow(mode, "MyGKrellm");

    window->setFramerateLimit(FPS);
}

void SFMLBuilder::CreateElements()
{
    event = sf::Event();
    circle = new sf::CircleShape(10.0f);
    circle->setOrigin(5.0f, 5.0f);
    circle->setPosition(150.0f, 150.0f);
}
