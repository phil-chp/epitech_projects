/*
** EPITECH PROJECT, 2021
** stack_test
** File description:
** st_destroy
*/

#include <stdlib.h>
#include "stack.h"

void st_destroy(stack_man_t *st)
{
    st_flush(st);
    if (st) free(st);
    st = NULL;
}
