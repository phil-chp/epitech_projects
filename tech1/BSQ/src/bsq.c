/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Bsq root function
*/

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

void bsq(t_table *table)
{
    int i = 0;

    if (table->y > 1 && table->x > 1) {
        populate_by_weight(table);
        place_square(table);
    } else if (table->x == 1 && table->y > 1)
        search_pos_y(table);
    else
        search_pos_x(table);
    for (; i < table->x; i++)
        (write(1, table->board[i], table->y + 1) == -1);

    free_memory(table);
}
