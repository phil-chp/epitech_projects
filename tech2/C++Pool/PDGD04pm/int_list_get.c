/*
** EPITECH PROJECT, 2022
** PDG-D4-PM
** File description:
** int_list_misc
*/

#include <stddef.h>
#include "int_list.h"

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int i = 0;

    for (; list; i++, list = list->next);
    return (i);
}

int int_list_get_elem_at_front(int_list_t list)
{
    return (list ? list->value : 0);
}

int int_list_get_elem_at_back(int_list_t list)
{
    int_node_t *temp = list;

    if (temp) {
        for (; temp->next; temp = temp->next);
        return (temp->value);
    } else {
        return (0);
    }
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    int_node_t *temp = list;

    if (position == 0) {
        return (int_list_get_elem_at_front(list));
    }
    if (temp && position < int_list_get_size(list)) {
        for (size_t i = 0; i < position; i++, temp = temp->next);
        return (temp->value);
    } else {
        return (0);
    }
}
