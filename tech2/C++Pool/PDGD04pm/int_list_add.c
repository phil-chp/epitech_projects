/*
** EPITECH PROJECT, 2022
** PDG-D4-PM
** File description:
** int_list_misc
*/

#include <stddef.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_node_t *new_node;

    new_node = malloc(sizeof(int_node_t));
    if (!new_node) {
        return (false);
    }
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return (true);
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_node_t *new_node;

    new_node = malloc(sizeof(int_node_t));
    if (!new_node) {
        return (false);
    }
    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr) {
        int_node_t *temp = *front_ptr;
        for (; temp->next; temp = temp->next);
        temp->next = new_node;
    } else {
        (*front_ptr) = new_node;
    }
    return (true);
}

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem, \
                                        unsigned int position)
{
    int_node_t *new_node;

    if (position == 0) {
        return (int_list_add_elem_at_front(front_ptr, elem));
    }
    new_node = malloc(sizeof(int_node_t));
    if (!new_node || position > int_list_get_size(*front_ptr)) {
        return (false);
    }
    new_node->value = elem;
    new_node->next = NULL;
    int_node_t *temp = *front_ptr;
    for (size_t i = 0; i < position - 1; i++, temp = temp->next);
    new_node->next = temp->next;
    temp->next = new_node;
    return (true);
}
