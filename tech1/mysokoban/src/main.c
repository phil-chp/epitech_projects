/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** main
*/

#include <stdlib.h>
#include "sokoban.h"
#include "my.h"

static int check_help_message(char *param)
{
    if (param[0] == '-' && param[1] == 'h') {
        my_putstr("USAGE\n\r");
        my_putstr("    ./my_sokoban map\n\r");
        my_putstr("DESCRIPTION\n\r");
        my_putstr("    map   file representing the warehouse map, ");
        my_putstr("containing '#' for walls,\n\r");
        my_putstr("          'P' for the player, 'X' for boxes and 'O' ");
        my_putstr("for storage locations.\n\r");
        return (0);
    }
    return (2);
}

static int win_condition(goals_t *goals)
{
    for (goals = goals->head; goals->next; goals = goals->next)
        if (goals->state == 0) return (1);
    return (0);
}

static int main_loop(mov_t *mov, goals_t *goals, int *dim, char *map)
{
    int return_code = -1;
    int n = 0;

    while (return_code == -1) {
        n = check_screen_size(mov, dim, map, n);
        mov->key = getch();

        mvprintw(15, 15, "%d    ", mov->key);
        if (mov->key > 64 && mov->key < 69)
            handle_move(mov);
        refresh();
        return_code = check_boxes(dim);
        check_goals(goals);
        if (mov->key == ' ') return_code = 2;
        if (win_condition(goals) == 0) return_code = 0;
    }
    return (return_code);
}

int main(int ac, char **av)
{
    int return_code = 2;
    goals_t *goals;
    mov_t *mov;
    char *map;

    if (ac != 2)
        ERROR("my_sokoban: Wrong parameters\n\rHELP: ./my_sokoban -h\n\r");
    return_code = check_help_message(av[1]);
    while (return_code == 2) {
        map = av[1];
        mov = init_mov();
        int *dim = init_ncurses(mov, &map);
        goals = init_goals('O');
        return_code = main_loop(mov, goals, dim, map);
        destroy_all(mov, goals, dim, map);
    }
    return (return_code);
}
