/*
** EPITECH PROJECT, 2022
** PDG-D4-PM (Workspace)
** File description:
** list_misc
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

bool list_is_empty(list_t list)
{
    return (list ? false : true);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    for (size_t i = 0; list; i++, list = list->next) {
        val_disp(list->value);
    }
}

void list_clear(list_t *front)
{
    node_t *temp = *front;

    while (temp) {
        *front = (*front)->next;
        free(temp);
        temp = *front;
    }
    *front = NULL;
}
