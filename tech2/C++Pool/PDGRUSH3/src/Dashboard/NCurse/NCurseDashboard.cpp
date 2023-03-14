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

#include "NCurseDashboard.hpp"

NCurseDashboard::NCurseDashboard()
    : Dashboard(), Configurable()
{
     NCurseDashboardConfig *config = new NCurseDashboardConfig;

    config->width = 0;
    config->height = 0;
    config->x = 0;
    config->y = 0;
    this->setConfig(config);

}

NCurseDashboard::~NCurseDashboard()
{
    // do nothing
}
