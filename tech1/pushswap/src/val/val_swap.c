/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** Swaps the first and second elements of a list
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

void val_swap(sort_t *list, int space)
{
    sort_t *fir = list;
    sort_t *sec = list->next;

    if (fir == NULL || sec == NULL)
        return;
    int temp = fir->n;
    list->n = sec->n;
    list->next->n = temp;
    if (space != 1)
        my_putchar(' ');
    my_putstr("sa");
}
