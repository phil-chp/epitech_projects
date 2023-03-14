/*
** EPITECH PROJECT, 2021
** corewar (Workspace)
** File description:
** init_alive_list
*/

#include "corewar.h"

bool init_alive_list(corewar_t *cw)
{
    champs_t *iter;

    if (!(cw->alive = malloc(sizeof(char) * (cw->teams + 1))))
        return (1);
    for (size_t i = 0; i < (size_t)cw->teams; i++)
        cw->alive[i] = 0;
    cw->alive[(size_t)cw->teams] = -1;
    return (0);
}
