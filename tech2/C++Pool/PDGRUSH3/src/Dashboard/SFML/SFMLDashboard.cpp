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

#include "SFMLDashboard.hpp"
#include "DashboardWidget.hpp"

SFMLDashboard::SFMLDashboard()
    : Dashboard(), Configurable()
{
    SFMLDashboardConfig *config = new SFMLDashboardConfig;
    config->width = 0;
    config->height = 0;
    config->x = 0;
    config->y = 0;
}

SFMLDashboard::~SFMLDashboard()
{

}
