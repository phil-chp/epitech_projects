/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** st_match
*/

#include "stack.h"

int st_match(stack_man_t *st, cell_t c)
{
    stack_t *item;

    item = st->top;
    for ( ; item; item = item->prev)
        if (item->node.pos.x == c.x   \
        &&  item->node.pos.y == c.y   \
        &&  item->node.visited == true)
            return (1);
    return (0);
}
