/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** user_plays
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"

void send_signal(int pid, char *shoot)
{
    char *res = dec_to_bin(shoot);

    for (int i = 0; i < 6; i++) {
        if (res[i] == '0') {
            kill(pid, SIGUSR1);
            signal(SIGUSR1, handler);
        } else {
            kill(pid, SIGUSR2);
            signal(SIGUSR2, handler);
        }
        if (i != 5)
            pause();
        usleep(10000);
    }
    return;
}

char **add_shoot(char **map, char *shoot)
{
    int i = (shoot[0] * 2) - 128;
    int j = shoot[1] - 47;

    map[j][i] = 'x';
    return (map);
}

int play_usr1(plan_t *plan, char *pos, int x)
{
    if ((aread_pos(plan, pos, 1)) == 84)
        return (84);
    plan->arr_pos1 = set_array_pos(plan->usr_map, plan->arr_pos1, plan->pos1);
    if (plan->arr_pos1 == NULL)
        return (84);
    my_lprintf("\nmy positions:\n%t\nenemy's positions:\n%t\n",   \
                                        plan->arr_pos1, plan->map_usr1);
    if (x == 1)
        receive_pos(plan, plan->pid2);
    else if (x == 0)
        my_putstr("\nattack: ");
    else
        my_putstr("Wrong position\nattack: ");
    if (x == 0 || x == 2) {
        send_pos(plan, pos, 1, plan->pid2);
        return (1);
    } else
        return (0);
}

int play_usr2(plan_t *plan, char *pos, int x)
{
    if ((aread_pos(plan, pos, 2)) == 84)
        return (84);
    plan->arr_pos2 = set_array_pos(plan->usr_map, plan->arr_pos2, plan->pos2);
    if (plan->arr_pos2 == NULL)
        return (84);
    my_lprintf("\nmy positions:\n%t\nenemy's positions:\n%t\n",     \
                                            plan->arr_pos2, plan->map_usr2);
    if (x == 0)
        receive_pos(plan, plan->pid1);
    else if (x == 1)
        my_putstr("\nattack: ");
    else
        my_putstr("Wrong position\nattack: ");
    if (x == 1 || x == 2) {
        send_pos(plan, pos, 2, plan->pid1);
        return (1);
    } else
        return (0);
}
