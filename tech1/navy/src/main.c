/*
** EPITECH PROJECT, 2020
** navy
** File description:
** main
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "lib.h"

static void game_final(plan_t *plan)
{
    if (plan->end == 1)
        my_putstr("Player one wins!\n");
    else if (plan->end == 2)
        my_putstr("Player two wins!\n");
    return;
}

static int game_loop(plan_t *plan, int ac, char **av)
{
    if ((map_maker(MAP_FILE, plan)) == 84)
        return (84);
    while (plan->end == 0 || plan->end == 1 || plan->end == 2) {
        if (ac == 2)
            plan->end = play_usr1(plan, av[1], plan->end);
        else if (ac == 3)
            plan->end = play_usr2(plan, av[2], plan->end);
        else
            return (84);
    }
    if (plan->end == 84)
        return (84);
    game_final(plan);
    return (0);
}

static int game_manager(plan_t *plan, int ac, char **av)
{
    if (ac == 2) {
        if ((usr1(plan)) == 84)
            return (84);
    } else {
        plan->pid1 = my_getnbr(av[1]);
        if ((usr2(plan)) == 84)
            return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    plan_t *plan;

    if (ac < 2 || ac > 3) {
        ERR_ARGS;
        return (84);
    }
    if (ac == 2)
        plan = init_plan(0);
    else
        plan = init_plan(1);
    if (plan == NULL)
        return (84);
    if ((game_manager(plan, ac, av)) == 84)
        return (84);
    if ((game_loop(plan, ac, av)) == 84)
        return (84);
    return (0);
}
