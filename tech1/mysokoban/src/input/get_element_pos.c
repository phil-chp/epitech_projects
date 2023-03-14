/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** get_element_pos
*/

#include <stdlib.h>
#include "sokoban.h"

int **find_all_elements(char c, int *count)
{
    unsigned int elem = c;
    int **coords;
    int n = 0;

    coords = malloc(sizeof(int *) * 2);
    if (!coords) ERROR("my_sokoban: Out of memory\n\r");
    for (int i = 0; i < LINES; i++)
        for (int j = 0; j < COLS; j++)
            (mvinch(i, j) == elem) ? ((*count)++) : (0);
    coords[0] = malloc(sizeof(int) * (*count));
    coords[1] = malloc(sizeof(int) * (*count));
    if (!coords[0] || !coords[1]) {
        free(coords);
        ERROR("my_sokoban: Out of memory\n\r");
    }
    for (int i = 0; i < LINES; i++)
        for (int j = 0; j < COLS; j++)
            (mvinch(i, j) == elem)  \
            ? (coords[0][n] = i, coords[1][n] = j, n++) : (0);
    return (coords);
}

void get_element_pos(mov_t *mov, char c)
{
    unsigned int elem;
    int n = 0;

    mov->x = -1;
    mov->y = -1;
    elem = c;
    for (int i = 0; n != 1 && i < LINES; i++)
        for (int j = 0; n != 1 && j < COLS; j++)
            (mvinch(i, j) == elem) && (mov->x = i, mov->y = j, n = 1);
}
