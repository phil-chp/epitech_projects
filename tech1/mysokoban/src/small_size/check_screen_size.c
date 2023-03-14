/*
** EPITECH PROJECT, 2021
** my_sokoban (Workspace)
** File description:
** check_screen_size
*/

#include "sokoban.h"

static int get_input_center(char *user_input)
{
    int len;

    len = my_strlen(user_input);
    if (len % 2 != 0)
        len = (len - 1) / 2;
    else
        len /= 2 - 1;
    return (len);
}

static int get_center(int value, int len)
{
    int res;

    res = value / 2 - len;
    if (value % 2 != 0)
        res -= 1;
    return (res);
}

static void set_input(char *user_input)
{
    int x;
    int y;
    int len;

    len = get_input_center(user_input);
    x = get_center(COLS, len);
    y = get_center(LINES, 0);
    move(y, x);
    printw("%s", user_input);
}

int check_screen_size(mov_t *mov, int *dim, char *map, int n)
{
    if (COLS < dim[0] || LINES < dim[1]) {
        clear();
        set_input("> TOO SMALL <");
        n = 1;
    } else if (n == 1) {
        n = 0;
        clear();
        mvprintw(0, 0, "%s\r", map);
        get_element_pos(mov, 'P');
    }
    return (n);
}
