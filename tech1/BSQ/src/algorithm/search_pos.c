/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Search pos
*/

#include "struct.h"

void search_pos_x(t_table *table)
{
    for (int x = 0; x < table->x; x++)
        if (table->board[0][x] == '.') {
            table->board[0][x] = 'x';
            x = table->x + 1;
        }
    return;
}

void search_pos_y(t_table *table)
{
    for (int y = 0; y < table->y; y++)
        if (table->board[0][y] == '.') {
            table->board[0][y] = 'x';
            y = table->y + 1;
        }
    return;
}
