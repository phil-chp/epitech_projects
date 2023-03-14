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

#include "Dashboard.hpp"

Dashboard::~Dashboard()
{
    // do nothing
}

Dashboard::Dashboard()
{
}

void Dashboard::addWidget(DashboardWidget *widget)
{
    _widgetList.push_back(widget);
}

std::vector<DashboardWidget *> Dashboard::getWidgetList()
{
    return (this->_widgetList);
}
