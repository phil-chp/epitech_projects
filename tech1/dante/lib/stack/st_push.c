/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** st_push
*/

#include <stdlib.h>
#include "stack.h"

int st_push(stack_man_t *st, node_t node)
{
    stack_t *temp;

    if (st_isfull(st))
        return (0);
    if ((temp = malloc(sizeof(stack_t))) == NULL)
        return (1);
    temp->node = node;
    if (st->top)
        temp->prev = st->top;
    else
        temp->prev = NULL;
    st->top = temp;
    st->count++;
    return (0);
}
