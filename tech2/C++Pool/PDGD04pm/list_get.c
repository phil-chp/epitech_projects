/*
** EPITECH PROJECT, 2022
** PDG-D4-PM
** File description:
** list_get
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"

unsigned int list_get_size(list_t list)
{
    unsigned int i = 0;

    for (; list; i++, list = list->next);
    return (i);
}

void *list_get_elem_at_front(list_t list)
{
    return (list ? list->value : NULL);
}

void *list_get_elem_at_back(list_t list)
{
    node_t *temp = list;

    if (temp) {
        for (; temp->next; temp = temp->next);
        return (temp->value);
    } else {
        return (NULL);
    }
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    node_t *temp = list;

    if (position == 0) {
        return (list_get_elem_at_front(list));
    }
    if (temp && position < list_get_size(list)) {
        for (size_t i = 0; i < position; i++, temp = temp->next);
        return (temp->value);
    } else {
        return (NULL);
    }

}
