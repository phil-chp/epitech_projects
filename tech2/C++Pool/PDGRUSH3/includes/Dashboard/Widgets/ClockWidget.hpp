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

#ifndef CLOCKWIDGET_HPP_
# define CLOCKWIDGET_HPP_

#include "DashboardWidget.hpp"
#include "Configurable.hpp"
#include "ClockModule.hpp"

typedef struct ClockWidgetConfig {
    int x;
    int y;
    int width;
    int height;
} ClockWidgetConfig;

class ClockWidget
    : public DashboardWidget, public Configurable<ClockWidgetConfig>
{
    public:
        ClockWidget();
        ~ClockWidget();
        void refresh() override;
    private:
        ClockModule *_clockModule;
};
#endif /* !CLOCKWIDGET_HPP_ */
