/*
** EPITECH PROJECT, 2022
** PDG-D4-PM (Workspace)
** File description:
** list_del
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"

bool list_del_elem_at_front(list_t *front_ptr)
{
    node_t *temp;

    if (!*front_ptr)
        return (false);
    temp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(temp);
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    node_t *temp = *front_ptr;

    if (*front_ptr) {
        for (; temp->next->next; temp = temp->next);
        free(temp->next);
        temp->next = NULL;
    }
    return (list_is_empty(*front_ptr));

}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    node_t *temp = *front_ptr;
    unsigned int len;

    len = list_get_size(*front_ptr);
    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    if (temp && position < len) {
        size_t i = 0;
        for (; temp->next->next && i < position - 1; i++, temp = temp->next);
        node_t *temp_next = temp->next->next;
        free(temp->next);
        temp->next = temp_next;
    } else if (position >= len) {
        return (false);
    }
    return (list_is_empty(*front_ptr));
}
