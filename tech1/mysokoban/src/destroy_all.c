/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** destroy_all
*/

#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"

void destroy_all(mov_t *mov, goals_t *goals, int *dim, char *map)
{
    for (goals = goals->head; goals->next;) {
        goals_t *temp = goals;
        goals = goals->next;
        if (temp) free(temp);
    }
    if (goals) free(goals);
    if (mov) free(mov);
    if (dim) free(dim);
    if (map) free(map);
    clear();
    endwin();
}
