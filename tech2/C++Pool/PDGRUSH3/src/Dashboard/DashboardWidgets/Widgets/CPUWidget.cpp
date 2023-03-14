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

#include "CPUWidget.hpp"

CPUWidget::~CPUWidget()
{
    // do nothing
}

CPUWidget::CPUWidget()
    : DashboardWidget(), Configurable()
{
    CPUWidgetConfig *config = new CPUWidgetConfig;
    config->x = 0;
    config->y = 0;
    config->width = 0;
    config->height = 0;

    this->setConfig(config);
    this->_cpu = new CPUModule::Cores();
}

void CPUWidget::refresh()
{
    this->_cpu->refresh();
}
