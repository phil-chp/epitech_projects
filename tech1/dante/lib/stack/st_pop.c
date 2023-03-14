/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** st_pop
*/

#include <stdlib.h>
#include "stack.h"

node_t st_pop(stack_man_t *st)
{
    stack_t *temp;
    node_t node;

    if (st_isempty(st)) {
        node.pos.x = node.pos.y = -1;
        return (node);
    }
    node = st->top->node;
    temp = st->top;
    st->top = st->top->prev;
    st->count--;
    if (temp) free(temp);
    temp = NULL;
    return (node);
}
