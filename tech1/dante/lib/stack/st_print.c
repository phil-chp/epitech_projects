/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** st_display
*/

#include <stdio.h>
#include "stack.h"

void st_print(stack_t *item)
{
    if (item) {
        printf("prev: %p\t(%d, %d)\tparent: %p\n", &item->prev, item->node.pos.x, item->node.pos.y, &item->node.parent);
        st_print(item->prev);
    }
}
