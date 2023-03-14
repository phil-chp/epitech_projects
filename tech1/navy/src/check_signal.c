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

char g_sig_value;

void pos_handler(int sig)
{
    if (sig == SIGUSR1) {
        g_sig_value = '0';
    } else {
        g_sig_value = '1';
    }
}

char *receive_signal(int pid)
{
    struct sigaction act = {0};
    act.sa_handler = &pos_handler;
    char *res = malloc(sizeof(char) * 7);

    if (res == NULL)
        return (NULL);
    for (int i = 0; i < 6; i++) {
        if ((sigaction(SIGUSR1, &act, NULL)) < 0)
            return (NULL);
        if ((sigaction(SIGUSR2, &act, NULL)) < 0)
            return (NULL);
        int sig = (g_sig_value == '0') ? (SIGUSR1) : (SIGUSR2);
        if (i != 5)
            pause();
        usleep(10000);
        res[i] = g_sig_value;
        kill(pid, sig);
    }
    res[7] = '\0';
    return (bin_to_dec(res));
}

char *check_pos(plan_t *plan, char *pos, int pid)
{
    char *c = my_strupcase(term_getline());
    if (c == NULL)
        return (NULL);
    if (!(c[0] >= 'A' && c[0] <= 'H') || !(c[1] >= '1' && c[1] <= '9')) {
        if (pid == plan->pid2)
            play_usr1(plan, pos, 2);
        else if (pid == plan->pid1)
            play_usr2(plan, pos, 2);
    }
    return (c);
}

int send_pos(plan_t *plan, char *pos, int x, int pid)
{
    if (x) {}
    char *position = NULL;

    if ((position = check_pos(plan, pos, pid)) == NULL)
        return (84);
    send_signal(pid, position);
    if (pid == plan->pid2)
        plan->map_usr1 = add_shoot(plan->map_usr1, position);
    else
        plan->map_usr2 = add_shoot(plan->map_usr2, position);

    my_lprintf("%s: [WIP]", position);
    return (0);
}

void receive_pos(plan_t *plan, int pid)
{
    my_putstr("waiting for enemy's attack...\n");
    char *position = receive_signal(pid);

    if (pid == plan->pid2)
        plan->arr_pos2 = add_shoot(plan->arr_pos2, position);
    else
        plan->arr_pos1 = add_shoot(plan->arr_pos1, position);

    my_lprintf("%s: [WIP]\n", position);
}
