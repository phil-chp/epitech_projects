/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** Rotates the list to the left or right
*/

#include "struct.h"
#include "my.h"

void val_rotate(index_t *a_ind, int n, int space)
{
    if (space != 1)
        my_putchar(' ');
    if (n == 0) {
        a_ind->tail = a_ind->tail->next;
        my_putstr("ra");
    } else if (n == 1) {
        a_ind->tail = a_ind->tail->prev;
        my_putstr("rra");
    }
}
