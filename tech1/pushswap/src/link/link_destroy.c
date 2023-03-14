/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** Destroys a lists and its index
** builds nums in the case of l_a
*/

#include <stdlib.h>
#include "struct.h"

void link_destroy(sort_t **lists, index_t *ind)
{
    lists[0] = ind->tail->next;

    for (; lists[0] != ind->tail; ) {
        sort_t *temp = lists[0];
        lists[0] = lists[0]->next;
        free(temp);
    }
}
