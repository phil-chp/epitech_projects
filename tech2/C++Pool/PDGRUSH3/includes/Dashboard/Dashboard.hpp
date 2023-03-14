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

#ifndef DASHBOARD_HPP_
#define DASHBOARD_HPP_

#include "DashboardWidget.hpp"
#include "Configurable.hpp"
#include <vector>
#include <iostream>
#include <list>

class IMonitorDisplay
{
    public:
        virtual ~IMonitorDisplay() = default;


};

class Dashboard : public IMonitorDisplay
{
    public:
        ~Dashboard();
        Dashboard();
        void addWidget(DashboardWidget *widget);
        std::vector<DashboardWidget *> getWidgetList();
    private:
        std::vector<DashboardWidget *> _widgetList;
};

#endif /* !DASHBOARD_HPP_ */
