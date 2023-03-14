/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** st_pop
*/

#include <stdlib.h>
#include "stack.h"

void *st_pop(stack_man_t *st)
{
    void *data;
    stack__t *temp;

    data = st->top->data;
    temp = st->top;
    st->top = st->top->prev;
    st->count--;
    if (temp) free(temp);
    temp = NULL;
    return (data);
}
