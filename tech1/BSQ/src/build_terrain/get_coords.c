/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Get X and get Y for table dimentions
*/

#include <stdlib.h>
#include "struct.h"
#include "errors.h"
#include "my.h"

void get_y(t_table *table, char *temp_board)
{
    table->y = 0;
    if (my_strlen(temp_board) <= 1) {
        table->y = 1;
        return;
    }
    if (table->x == 1) {
        while (temp_board[table->y])
            table->y++;
        return;
    }
    while (temp_board[table->y] != '\n')
        table->y++;
    return;
}

int get_x(t_table *table, char *buff)
{
    char *temp_size;
    int x = 0;
    int i;

    while (buff[x] != '\n')
        x++;
    temp_size = malloc(sizeof(char) * (x + 1));
    (temp_size == NULL) && (MEM_ERROR, exit(84), 0);
    for (i = 0; i < x; i++)
        temp_size[i] = buff[i];
    temp_size[i] = '\0';
    table->x = my_getnbr(temp_size);
    free(temp_size);
    return (x);
}
