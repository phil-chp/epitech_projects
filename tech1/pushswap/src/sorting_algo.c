/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** sorting_algo
*/

#include "struct.h"

static int sort_security(sort_t *l_a, index_t *a_ind, int *pos, int *moves)
{
    if (l_a->next == l_a)
        return (1);
    for ( ; l_a != a_ind->tail; l_a = l_a->next) {
        (l_a->n > l_a->next->n) ? (*moves += 1) : (*pos += 1);
    }
    if (*moves == 0)
        return (1);
    return (0);
}

void sorting_algo(sort_t *l_a, index_t *a_ind, int spaces)
{
    int pos = 0, moves = 0;

    if (sort_security(l_a, a_ind, &pos, &moves) == 1)
        return;
    l_a = a_ind->tail->next;
    if (pos == 0) {
        val_swap(l_a, spaces);
        (moves == 1) && (val_swap(l_a, 0), val_rotate(a_ind, 0, 0), 0);
        for (; moves > 0; moves--)
            val_rotate(a_ind, 0, 0);
    } else {
        for ( ; pos > 0; pos--)
        val_rotate(a_ind, 0, spaces);
        for ( ; l_a > l_a->next && moves > 0; moves--, pos = 1) {
            val_swap(l_a, 0);
            val_rotate(a_ind, 0, 0);
        }
        (moves == 1) ? (val_rotate(a_ind, 0, 0)) : 0;
    }
    (pos != 0) ? (sorting_algo(l_a, a_ind, 0)) : 0;
}
