/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** Moves the first element of l_a to l_b or vice versa
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

sort_t *val_move(sort_t *fir, index_t *ind)
{
    fir->prev->next = fir->next;
    fir->next->prev = fir->prev;
    fir->next = ind->tail->next;
    fir->prev = ind->tail;
    ind->tail->next = fir;
    ind->tail->next->next->prev = fir;
    if (ind->tail == ind->tail->next)
        ind->tail->prev = fir;
    my_putstr("pa");
    return (fir);
}
