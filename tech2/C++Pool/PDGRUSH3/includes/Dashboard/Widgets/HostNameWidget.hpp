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

#ifndef HOSTNAMEWIDGET_HPP_
#define HOSTNAMEWIDGET_HPP_

#include "DashboardWidget.hpp"
#include "Configurable.hpp"
#include "HostNameModule.hpp"

typedef struct HostNameWidgetConfig {
    int x;
    int y;
    int width;
    int height;
} HostNameWidgetConfig;

class HostNameWidget
    : public DashboardWidget, public Configurable<HostNameWidgetConfig>
{
    public:
        HostNameWidget();
        ~HostNameWidget();
        void refresh() override;
    private:
        HostNameModule *_hostName;
};

#endif /* !HOSTNAMEWIDGET_HPP_ */
