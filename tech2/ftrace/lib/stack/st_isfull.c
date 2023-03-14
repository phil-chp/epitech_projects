/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** st_isfull
*/

#include "stack.h"

int st_isfull(stack_man_t *st)
{
    return (st->max > 0 && st->count >= st->max);
}
