/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** Main sorter file
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

void sorter(int n, int *nums)
{
    sort_t *l_a = NULL;
    sort_t *l_b = malloc(sizeof(*l_b));
    index_t *a_ind = malloc(sizeof(*a_ind));
    index_t *b_ind = malloc(sizeof(*b_ind));
    sort_t **lists =  malloc(sizeof(*lists) * 2);
    lists[0] = l_a;
    lists[1] = l_b;
    b_ind->tail = lists[1];

    link_build(lists, &a_ind, nums, n);
    sorting_algo(lists[0], a_ind, 1);
    my_putchar('\n');
    lists[0] = a_ind->tail->next;
    lists[0]->prev->next = NULL;
    free(lists[1]);
}
