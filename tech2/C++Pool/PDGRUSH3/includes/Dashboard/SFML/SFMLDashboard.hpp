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

#ifndef SFMLDASHBOARD_HPP_
# define SFMLDASHBOARD_HPP_

#include "Dashboard.hpp"
#include "DashboardWidget.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

typedef struct SFMLDashboardConfig {
   int width;
   int height;
   int x;
   int y;
} SFMLDashboardConfig;

class SFMLDashboard
        : public Dashboard, public Configurable<SFMLDashboardConfig>
{
    public:
        SFMLDashboard();
        ~SFMLDashboard();
};

#endif /* !SFMLDASHBOARD_HPP_ */
