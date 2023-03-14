/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Place square in board
*/

#include "struct.h"

void place_square(t_table *table)
{
    int x = table->temp[0][table->y] + 1;
    int y = table->temp[0][table->y + 1] + 1;
    int max;

    if (table->temp[0][table->y] == -1)
        return;
    max = table->temp[table->temp[0][table->y]][table->temp[0][table->y + 1]];
    for (int n = max; n > 0; n--)
        for (int m = max; m > 0; m--)
            table->board[x - n][y - m] = 'x';
    return;
}
