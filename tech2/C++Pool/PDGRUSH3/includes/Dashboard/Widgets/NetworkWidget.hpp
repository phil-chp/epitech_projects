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

#ifndef CPP_NETWORKWIDGET_HPP
#define CPP_NETWORKWIDGET_HPP

#include "DashboardWidget.hpp"
#include "Configurable.hpp"
#include "NetworkModule.hpp"

typedef struct NetworkWidgetConfig {
    int x;
    int y;
    int width;
    int height;
} NetworkWidgetConfig;

class NetworkWidget
    : public DashboardWidget, public Configurable<NetworkWidgetConfig>
{
    public:
        NetworkWidget();
        ~NetworkWidget();
        void refresh() override;

    private:
        NetworkModule *_NetworkModule;
};

#endif /* !CPP_NETWORKWIDGET_HPP */
