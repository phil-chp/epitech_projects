/*
** EPITECH PROJECT, 2021
** stack_test
** File description:
** st_flush
*/

#include "stack.h"

void st_flush(stack_man_t *st)
{
    for (; !st_isempty(st); )
        st_pop(st);
}
