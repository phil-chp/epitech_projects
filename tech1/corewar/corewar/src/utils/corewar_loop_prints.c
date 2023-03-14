/*
** EPITECH PROJECT, 2021
** corewar (Workspace)
** File description:
** corewar_loop_prints
*/

#include "corewar.h"

void ping_alive(champs_t *iter)
{
    miniprint("The player %d(%s)is alive.\n",   \
        iter->id,                               \
        iter->content.prog_name);
}

bool handle_ending(char teams, champs_t **champs)
{
    champs_t *iter;

    if (!(*champs))
        return (1);
    for (iter = (*champs)->head; iter && !iter->state; iter = iter->next);
    miniprint("The player %d(%s)has won.\n",  \
        iter->id,                             \
        iter->content.prog_name);
    return (0);
}
