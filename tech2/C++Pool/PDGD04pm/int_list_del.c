/*
** EPITECH PROJECT, 2022
** PDG-D4-PM
** File description:
** int_list_misc
*/

#include <stddef.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_node_t *temp;

    if (!*front_ptr)
        return (false);
    temp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(temp);
    return (true);
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_node_t *temp = *front_ptr;

    if (*front_ptr) {
        for (; temp->next->next; temp = temp->next);
        free(temp->next);
        temp->next = NULL;
    }
    return (int_list_is_empty(*front_ptr));
}

bool int_list_del_elem_at_position(int_list_t *front_ptr, \
                                        unsigned int position)
{
    int_node_t *temp = *front_ptr;
    unsigned int len;

    len = int_list_get_size(*front_ptr);
    if (position == 0)
        return (int_list_del_elem_at_front(front_ptr));
    if (temp && position < len) {
        size_t i = 0;
        for (; temp->next->next && i < position - 1; i++, temp = temp->next);
        int_node_t *temp_next = temp->next->next;
        free(temp->next);
        temp->next = temp_next;
    } else if (position >= len) {
        return (false);
    }
    return (int_list_is_empty(*front_ptr));
}
