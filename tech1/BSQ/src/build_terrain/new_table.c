/*
** EPITECH PROJECT, 2020
** New Table
** File description:
** Defines the table structure
*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "my.h"
#include "errors.h"

static void temp_builder(t_table *table, char *temp_board)
{
    int j = 0;
    int x = 0;

    table->temp = malloc(sizeof(int *) * (table->x + 1));
    (table->temp == NULL) && (MEM_ERROR, exit(84), 0);
    for (int k = 0; x <= table->x; x++, k = 0) {
        table->temp[x] = malloc(sizeof(int) * (table->y + 2));
        (table->temp[x] == NULL) && (MEM_ERROR, exit(84), 0);
        for (int i = j + 1; j < table->y + i && temp_board[j]; j++, k++) {
            (temp_board[j] == 'o') && (table->temp[x][k] = 0, k++, j++);
            (temp_board[j] == '.') && (table->temp[x][k] = 1);
        }
        (x < table->x - 1) && (table->temp[x][k - 1] = -1);
        (x == table->x) && (table->temp[x - 1][table->y] = - 1);
    }
    table->temp[x - 1][0] = -1;
    return;
}

static void board_builder(t_table *table, char *temp_board)
{
    int x = 0;
    int k = 0;

    table->board = malloc(sizeof(char *) * (table->x + 1));
    (table->board == NULL) && (MEM_ERROR, exit(84), 0);
    for (int j = 0; x <= table->x; x++, k = 0) {
        table->board[x] = malloc(sizeof(char) * (table->y + 2));
        (table->board[x] == NULL) && (MEM_ERROR, exit(84), 0);
        for (int i = j + 1; j < table->y + i && temp_board[j]; j++, k++)
            table->board[x][k] = temp_board[j];
        (x < table->x) && (table->board[x][k] = '\n');
    }
    table->board[x - 1] = NULL;
    free(temp_board);
    return;
}

static char *get_temp_board(char *buff, int x)
{
    char *temp_board;
    int i = 0;
    int y = 0;

    while (buff[y])
        y++;
    temp_board = malloc(sizeof(char) * (y + 1));
    (temp_board == NULL) && (MEM_ERROR, exit(84), 0);
    for (int j = x + 1; j < y; i++, j++)
        temp_board[i] = buff[j];
    temp_board[i] = '\0';
    return (temp_board);
}

int new_table(t_table *table, char *buff)
{
    int x = get_x(table, buff);
    char *temp_board = get_temp_board(buff, x);

    get_y(table, temp_board);
    temp_builder(table, temp_board);
    board_builder(table, temp_board);
    return (0);
}
