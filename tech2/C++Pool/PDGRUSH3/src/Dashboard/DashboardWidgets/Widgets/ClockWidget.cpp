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

#include "ClockWidget.hpp"

ClockWidget::~ClockWidget()
{
    // do nothing
}

ClockWidget::ClockWidget()
    : DashboardWidget(), Configurable()
{
    ClockWidgetConfig *config = new ClockWidgetConfig;
    config->x = 0;
    config->y = 0;
    config->width = 0;
    config->height = 0; // TODO
    this->setConfig(config);
    this->_clockModule = new ClockModule();
}

void ClockWidget::refresh()
{
    this->_clockModule->refresh();
}
