/*
** EPITECH PROJECT, 2021
** my_sokoban (Workspace)
** File description:
** check_boxes
*/

#include "sokoban.h"

static int is_blk(int x, int y)
{
    int wall_count_x = 0;
    int wall_count_y = 0;

    for (int wx = -1; wx < 2; wx += 2) {
        char c = mvinch(x + wx, y);
        if (c == '#' || c == 'X') wall_count_x++;
    }
    for (int wy = -1; wy < 2; wy += 2) {
        char c = mvinch(x, y + wy);
        if (c == '#' || c == 'X') wall_count_y++;
    }
    if (wall_count_x >= 1 && wall_count_y >= 1)
        return (1);
    return (0);
}

int check_boxes(int *dim)
{
    int blk_x = 0;
    int x_count = 0;

    for (int x = 0; x < dim[0]; x++) {
        for (int y = 0; y < dim[0]; y++) {
            int mem = x_count;
            char c = mvinch(x, y);
            if (c == 'X') x_count += 1;
            if (mem != x_count && c == 'X') blk_x += is_blk(x, y);
        }
    }
    if (x_count != 0 && x_count == blk_x)
        return (1);
    return (-1);
}
