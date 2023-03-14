/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** st_initialize
*/

#include <stdlib.h>
#include "stack.h"

stack_man_t *st_initialize(int max)
{
    stack_man_t *st;

    st = malloc(sizeof(stack_man_t));
    st->top  = NULL;
    st->max   = max;
    st->count = 0;
    return (st);
}
