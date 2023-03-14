/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** st_isempty
*/

#include "stack.h"

int st_isempty(stack_man_t *st)
{
    return (!st->top);
}
