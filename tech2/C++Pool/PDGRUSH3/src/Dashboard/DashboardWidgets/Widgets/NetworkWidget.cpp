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

#include "NetworkWidget.hpp"

NetworkWidget::~NetworkWidget()
{
    // do nothing
}

NetworkWidget::NetworkWidget()
    : DashboardWidget(), Configurable()
{
    NetworkWidgetConfig *config = new NetworkWidgetConfig;
    config->x = 0;
    config->y = 0;
    config->width = 0;
    config->height = 0;

    this->setConfig(config);
    this->_NetworkModule = new NetworkModule();

}

void NetworkWidget::refresh()
{
    this->_NetworkModule->refresh();
}
