/*
** EPITECH PROJECT, 2022
** PDG-D4-PM
** File description:
** int_list_misc
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

bool int_list_is_empty(int_list_t list)
{
    return (list ? false : true);
}

void int_list_dump(int_list_t list)
{
    for (size_t i = 0; list; i++, list = list->next) {
        printf("%d\n", list->value);
    }
}

void int_list_clear(int_list_t *front_ptr)
{
    int_node_t *temp = *front_ptr;

    while (temp) {
        *front_ptr = (*front_ptr)->next;
        free(temp);
        temp = *front_ptr;
    }
    *front_ptr = NULL;
}
