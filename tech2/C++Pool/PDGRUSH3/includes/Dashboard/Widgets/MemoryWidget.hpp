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

#ifndef CPP_MEMORYWIDGET_HPP
#define CPP_MEMORYWIDGET_HPP

#include "DashboardWidget.hpp"
#include "Configurable.hpp"
#include "MemoryModule.hpp"

typedef struct MemoryWidgetConfig {
    int x;
    int y;
    int width;
    int height;
} MemoryWidgetConfig;

class MemoryWidget
    : public DashboardWidget, public Configurable<MemoryWidgetConfig>
{
    public:
        MemoryWidget();
        ~MemoryWidget();
        void refresh() override;

    private:
        MemoryModule *_memoryModule;
};

#endif /* !CPP_MEMORYWIDGET_HPP */
