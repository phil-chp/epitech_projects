/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** SFML
*/

#include "SFMLBuilder.hpp"
#include <SFML/Graphics.hpp>

void SFMLGameLoop(SFMLBuilder *sfml)
{
    while (sfml->window->isOpen()) {
        while (sfml->window->pollEvent(sfml->event)) {
            if (sfml->event.type == sf::Event::Closed) sfml->window->close();
        }
        sfml->window->clear(sf::Color(0, 0, 0));
        // sfml->window->draw(sfml->circle);
        sfml->window->display();
    }
}
