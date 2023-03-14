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

#ifndef OS_WIDGET_HPP_
# define OS_WIDGET_HPP_

#include "DashboardWidget.hpp"
#include "Configurable.hpp"
#include "OSModule.hpp"

typedef struct OSWidgetConfig {
    int x;
    int y;
    int width;
    int height;
} OSWidgetConfig;

class OSWidget
        : public DashboardWidget, public Configurable<OSWidgetConfig>
{
    public:
        OSWidget();
        ~OSWidget();
        void refresh() override;
    private:
        OSModule *_os;
};

#endif /* !OS_WIDGET_HPP_ */
