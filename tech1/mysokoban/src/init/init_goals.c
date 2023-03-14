/*
** EPITECH PROJECT, 2021
** my_sokoban (Workspace)
** File description:
** init_goals
*/

#include <stdlib.h>
#include "sokoban.h"

static goals_t *set_goals_values(goals_t *goals, int i, int *x, int *y)
{
    goals->state = 0;
    goals->x = x[i];
    goals->y = y[i];
    return (goals);
}

static goals_t *create_goals(int count, int *x, int *y)
{
    goals_t *goals = NULL, *temp = NULL, *head = NULL;

    for (int i = 0; i < count; i++, goals = goals->next) {
        if (!goals) {
            goals = malloc(sizeof(goals_t));
            goals->prev = NULL;
            head = goals;
            head->head = head;
        }
        temp = malloc(sizeof(goals_t));
        goals->head = head;
        goals->next = temp;
        temp->prev = goals;
        goals = set_goals_values(goals, i, x, y);
    }
    goals->next = NULL;
    goals->head = head;
    goals = set_goals_values(goals, count, x, y);
    return (goals->head);
}

goals_t *init_goals(char c)
{
    goals_t *goals;
    int count = 0;
    int **coords;

    coords = find_all_elements(c, &count);
    goals = create_goals(count, coords[0], coords[1]);
    if (coords) free(coords);
    return (goals);
}
