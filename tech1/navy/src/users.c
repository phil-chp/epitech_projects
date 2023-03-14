/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** users
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"

int usr1(plan_t *plan)
{
    signal(SIGUSR2, handler);
    my_lprintf("my_pid : %d\nwaiting for enemy connection...\n", plan->pid1);
    pause();
    plan->pid2 = my_getnbr(read_file(INFO_FILE));
    if (plan->pid2 == 84)
        return (84);
    my_putstr("\nenemy connected\n");
    return (0);
}

int usr2(plan_t *plan)
{
    signal(SIGUSR1, handler);
    my_lprintf("my_pid : %d\n", plan->pid2);
    if ((write_file(INFO_FILE, my_get_str(plan->pid2), 1)) == 84)
        return (84);
    kill(plan->pid1, SIGUSR2);
    my_putstr("successfully connected\n");
    return (0);
}
