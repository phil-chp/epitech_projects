/*
** EPITECH PROJECT, 2022
** C POOL, rush-03-myGKrellm
** authored by:
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
**      Vitali DROUJKO <vitali.droujko@epitech.eu>
**      Mateo DEROCHE <mateo.deroche.epitech.eu>x
** File description:
** TODO
*/

#ifndef CPUWIDGET_HPP_
#define CPUWIDGET_HPP_

#include "DashboardWidget.hpp"
#include "Configurable.hpp"
#include "CPUModule.hpp"

typedef struct CPUWidgetConfig {
    int x;
    int y;
    int width;
    int height;
} CPUWidgetConfig;

class CPUWidget
    : public DashboardWidget, public Configurable<CPUWidgetConfig>
{
    public:
        CPUWidget();
        ~CPUWidget();
        void refresh() override;
    private:
        CPUModule::Cores *_cpu;
};

#endif /* !CPUWIDGET_HPP_ */
