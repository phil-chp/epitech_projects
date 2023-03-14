/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** init_mov
*/

#include <stdlib.h>
#include "sokoban.h"

mov_t *init_mov(void)
{
    mov_t *mov;

    mov = malloc(sizeof(mov_t));
    if (!mov) ERROR("my_sokoban: Out of memory\n\r");
    mov->x = -1;
    mov->y = -1;
    mov->pos = ' ';
    mov->old_pos = ' ';
    mov->key = -1;
    return (mov);
}
