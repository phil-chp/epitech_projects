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

#ifndef DASHBOARDWIDGET_HPP_
# define DASHBOARDWIDGET_HPP_

#include "DashboardWidget.hpp"
#include "Configurable.hpp"

class IMonitorModule
{
    public:
        virtual ~IMonitorModule() = default;
        virtual void refresh() = 0;

        // TODO add other methods
};

class DashboardWidget : public IMonitorModule
{
    public:
        ~DashboardWidget();
        DashboardWidget();
};

#endif /* !DASHBOARDWIDGET_HPP_ */
