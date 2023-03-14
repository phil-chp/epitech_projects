/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** map_maker
*/

#include <stdio.h>
#include "../lib.h"

int map_maker(char *path, plan_t *plan)
{
    if ((aread(plan, path)) == 84)
        return (84);
    if ((plan->usr_map = set_array(plan, plan->usr_map)) == NULL)
        return (84);
    if ((plan->map_usr1 = set_array(plan, plan->map_usr1)) == NULL)
        return (84);
    if ((plan->map_usr2 = set_array(plan, plan->map_usr2)) == NULL)
        return (84);
    return (0);
}
