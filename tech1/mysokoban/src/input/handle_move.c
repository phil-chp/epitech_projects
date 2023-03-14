/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** get_player_pos
*/

#include "sokoban.h"

static int handle_box(mov_t *mov, int x, int y)
{
    int nx, ny;
    char next;

    nx = mov->x - x;
    ny = mov->y - y;
    nx = (nx == 0) ? (mov->x) : (nx * -2 + mov->x);
    ny = (ny == 0) ? (mov->y) : (ny * -2 + mov->y);
    next = mvinch(nx, ny);
    if (next != ' ' && next != 'O') return (1);
    mvaddch(nx, ny, 'X');
    mvaddch(x, y, 'P');
    mov->pos = ' ';
    return (0);
}

static void check_move(mov_t *mov, int x, int y)
{
    mov->pos = mvinch(x, y);
    if (mov->pos != 'X') {
        if (mov->pos != 'P' && mov->pos != ' ' && mov->pos != 'O')
            return;
    } else {
        if (handle_box(mov, x, y) == 1)
            return;
    }
    mvaddch(x, y, 'P');
    mvaddch(mov->x, mov->y, mov->old_pos);
    mov->x = x;
    mov->y = y;
    mov->old_pos = mov->pos;
}

void handle_move(mov_t *mov)
{
    int x, y;

    x = mov->x;
    y = mov->y;
    switch (mov->key) {
        case 65:
            x--;
            break;
        case 66:
            x++;
            break;
        case 67:
            y++;
            break;
        case 68:
            y--;
    }
    check_move(mov, x, y);
}
