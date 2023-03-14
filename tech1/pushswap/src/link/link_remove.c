/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** Removes the first node of a linked list
*/

#include <stdlib.h>
#include "struct.h"

sort_t *link_remove(sort_t *list)
{
    if (list == NULL)
        return (list);
    if (list->next == list) {
        free(list);
        list = NULL;
        return (list);
    } else {
        list->prev->next = list->next;
        list->next->prev = list->prev;
        sort_t *temp = list;
        list = list->next;
        free(temp);
    }
    return (list);
}
