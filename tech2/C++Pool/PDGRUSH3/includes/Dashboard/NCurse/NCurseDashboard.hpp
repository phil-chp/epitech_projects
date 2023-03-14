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

#ifndef NCURSEDASHBOARD_HPP_
# define NCURSEDASHBOARD_HPP_

#include "Dashboard.hpp"
#include "DashboardWidget.hpp"
#include <vector>

typedef struct NCurseDashboardConfig {
   int width;
   int height;
   int x;
   int y;
} NCurseDashboardConfig;

class NCurseDashboard
    : public Dashboard, public Configurable<NCurseDashboardConfig>
{
    public:
        NCurseDashboard();
        ~NCurseDashboard();
};

#endif /* !NCURSEDASHBOARD_HPP_ */
