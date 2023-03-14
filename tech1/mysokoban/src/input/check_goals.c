/*
** EPITECH PROJECT, 2021
** my_sokoban (Workspace)
** File description:
** check_goals
*/

#include "sokoban.h"

void check_goals(goals_t *goals)
{
    for (goals = goals->head; goals->next; goals = goals->next) {
        char g = mvinch(goals->x, goals->y);
        if (g == 'X') {
            goals->state = 1;
        } else {
            goals->state = 0;
            (g != 'P') ? (mvaddch(goals->x, goals->y, 'O')) : (0);
        }
    }
}
