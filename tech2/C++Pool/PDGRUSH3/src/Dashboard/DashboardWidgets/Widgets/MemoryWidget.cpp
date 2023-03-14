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

#include "MemoryWidget.hpp"

MemoryWidget::~MemoryWidget()
{
    // do nothing
}

MemoryWidget::MemoryWidget()
    : DashboardWidget(), Configurable()
{
    MemoryWidgetConfig *config = new MemoryWidgetConfig;
    config->x = 0;
    config->y = 0;
    config->width = 0;
    config->height = 0;

    this->setConfig(config);
    this->_memoryModule = new MemoryModule();

}

void MemoryWidget::refresh()
{
    this->_memoryModule->refresh();
}
