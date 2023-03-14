/*
** EPITECH PROJECT, 2022
** C POOL, rush-03-myGKrellm
** authored by:
**    - Philippe CHEYPE <philippe.cheype@epitech.eu>
**    - Vitali DROUJKO <vitali.droujko@epitech.eu>
**    - Mateo DEROCHE <mateo.deroche.epitech.eu>
** File description:
** TODO
*/

#include "Errors.hpp"
#include "SFMLDashboard.hpp"
#include "NCurseDashboard.hpp"
#include "ClockWidget.hpp"
#include "CPUWidget.hpp"
#include "MemoryWidget.hpp"
#include "HostNameWidget.hpp"
#include "OSWidget.hpp"
#include "NetworkWidget.hpp"
#include "SFMLBuilder.hpp"
#include "NCurseBuilder.hpp"
#include <iostream>

int ArgumentChecker(int ac)
{
    if (ac != 2) {
        throw ArgumentError("USAGE: ./myGKrellm [OPTION]", "BAD ARGS");
        return (1);
    }
    return (0);
}

void NCurseGameLoop(NCurseBuilder *builder);

void SFMLGameLoop(SFMLBuilder *sfml);

template <typename Builder, typename Dashboard>
void game(std::string kind)
{
    Dashboard *dashboard = new Dashboard;
    dashboard->addWidget(new ClockWidget);
    dashboard->addWidget(new CPUWidget);
    dashboard->addWidget(new MemoryWidget);
    dashboard->addWidget(new HostNameWidget);
    dashboard->addWidget(new OSWidget);
    dashboard->addWidget(new NetworkWidget);

    Builder *builder = new Builder(dashboard);
    if (kind == "SFML") {
        SFMLGameLoop((SFMLBuilder *)builder);
    } else {
        NCurseGameLoop((NCurseBuilder *)builder);
    }
}

int main(int ac, char **av)
{
    if (ArgumentChecker(ac)) return (1);

    if (av[1] == std::string("--text") || av[1] == std::string("-t")) {
        game<NCurseBuilder, NCurseDashboard>("NCURSE");
    } else if (av[1] == std::string("--graphical") || av[1] == std::string("-g")) {
        game<SFMLBuilder, SFMLDashboard>("SFML");
    } else {
        throw ArgumentError("USAGE: ./myGKrellm [OPTION]", "BAD ARGS");
    }
    return (0);
}
