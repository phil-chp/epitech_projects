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

#include "HostNameWidget.hpp"

HostNameWidget::~HostNameWidget()
{
    // do nothing
}

HostNameWidget::HostNameWidget()
    : DashboardWidget(), Configurable()
{
    HostNameWidgetConfig *config = new HostNameWidgetConfig;
    config->x = 0;
    config->y = 0;
    config->width = 0;
    config->height = 0;

    this->setConfig(config);
    this->_hostName = new HostNameModule();
}

void HostNameWidget::refresh()
{
}
