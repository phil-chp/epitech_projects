/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** Creates a linked list with n elements and assigns values according to nums
*/

#include "struct.h"
#include "errors.h"

void link_build(sort_t **lists, index_t **ind, int *nums, int n)
{
    for (int i = n - 1; i >= 0; i--)
        if (link_add(&lists[0], nums[i]) == 1)
            (*ind)->tail = lists[0];
    (*ind)->tail->next->prev = (*ind)->tail;
    lists[1]->n = HANDLE;
    lists[1]->next = lists[1];
    lists[1]->prev = lists[1];
}
