/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** display_input
*/

#include <stdlib.h>
#include "sokoban.h"

static void handle_char_count(char *map)
{
    int x_count = 0;
    int o_count = 0;
    int p_count = 0;

    for (int i = 0; map[i]; i++) {
        if (map[i] == 'X') x_count++;
        if (map[i] == 'O') o_count++;
        if (map[i] == 'P') p_count++;
    }
    if (x_count != o_count) ERROR("my_sokoban: Bad X's and O's ratio\n\r");
    if (p_count != 1) ERROR("my_sokoban: Bad player count\n\r");
}

static void check_map(char *map)
{
    char to_check[] = " \n#XOP";
    int chars_len, map_len;

    handle_char_count(map);
    map_len = my_strlen(map);
    chars_len = my_strlen(to_check);
    for (int i = 0; i < map_len; i++) {
        int j = 0;
        for (; j < chars_len && to_check[j] != map[i]; j++);
        if (j == chars_len) {
            if (map) free(map);
            ERROR("my_sokoban: Invalid map\n\rHELP: ./my_sokoban -h\n\r");
        }
    }
}

static int *get_map_dimentions(char *map)
{
    int *dim;
    int x = 0, tx = 0;
    int y = 0;

    dim = malloc(sizeof(int) * 2);
    if (!dim) ERROR("my_sokoban: Out of memory\n\r");
    for (int i = 0; map[i]; i++, tx++) {
        if (map[i] == '\n' && tx >= x) {
            x = tx;
            tx = 0;
        }
        if (map[i] == '\n') {
            y++;
            tx = 0;
        }
    }
    dim[0] = x - 1;
    dim[1] = y + 1;
    return (dim);
}

int *set_map(char **path)
{
    char *map;
    int *dim;

    map = read_file(*path);
    if (!map)
        ERROR("my_sokoban: File not found\n\r");
    check_map(map);
    dim = get_map_dimentions(map);
    mvprintw(0, 0, "%s\r", map);
    *path = map;
    return (dim);
}
