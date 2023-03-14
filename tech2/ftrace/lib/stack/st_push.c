/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** st_push
*/

#include <stdlib.h>
#include "stack.h"

int st_push(stack_man_t *st, void *data)
{
    stack__t *temp;

    if (st_isfull(st))
        return (0);
    if ((temp = malloc(sizeof(stack__t))) == NULL)
        return (1);
    temp->data = data;
    if (st->top)
        temp->prev = st->top;
    else
        temp->prev = NULL;
    st->top = temp;
    st->count++;
    return (0);
}
