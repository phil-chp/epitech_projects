/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** init_ncurses
*/

#include <stdlib.h>
#include "sokoban.h"

static void set_params(void)
{
    cbreak();
    noecho();
    curs_set(0);
}

int *init_ncurses(mov_t *mov, char **map)
{
    int *dim;

    if (initscr() == NULL) {
        if (mov) free(mov);
        ERROR("my_sokoban: Unable to initialize screen\n\r");
    }
    set_params();
    dim = set_map(map);
    get_element_pos(mov, 'P');
    return (dim);
}
