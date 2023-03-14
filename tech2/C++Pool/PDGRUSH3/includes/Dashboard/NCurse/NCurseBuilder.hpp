/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** NCurseBuilder
*/

#ifndef NCURSE_BUILDER_HPP_
#define NCURSE_BUILDER_HPP_

#include "Configurable.hpp"
#include "NCurseDashboard.hpp"

typedef struct NCurseBuilderConfig {

} NCurseBuilderConfig;

class NCurseBuilder
    : public Configurable<NCurseBuilderConfig>
{
    public:
        NCurseBuilder(NCurseDashboard *dashboard);
        ~NCurseBuilder();
};

#endif /* !NCURSE_BUILDER_HPP_ */
