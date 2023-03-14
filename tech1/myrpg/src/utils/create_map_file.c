/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** file.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

char *my_add_str(char *dest, char *src, int count)
{
    int n;
    char *temp = malloc(sizeof(char *) * 25);
    count = (count == 0 ? 0 : 1);
    for (n = 0; src[n + count] != '\0'; n++)
        temp[n] = src[n + count];
    temp[n] = '\0';
    dest = my_strcat(dest, temp);
    free(temp);
    return dest;
}

char *add_stair(map_t **map, char *res, int stair)
{
    int count;
    map_t *init, *iter;

    for (iter = (*map)->head; iter->room != 0   \
    && iter->stair != stair; iter = iter->right);
    init = iter;
    for (int i = 0; i < 13; i++) {
        count = 0;
        for (iter = init, count = 0; iter; iter = iter->right, count++) {
            if (count == 10) break;
            my_add_str(res, iter->map[i], count);
        }
        res = my_strcat(res, "\n");
    }
    return res;
}

bool create_map_file(game_t *game)
{
    char *res = NULL;
    if (!(res = malloc(sizeof(char) * 13900)))
        return (1);
    res = my_strcpy(res, "1 - 'Basement'\n");
    add_stair(&game->map, res, 0);
    res = my_strcat(res, "2 - 'Caves'\n");
    add_stair(&game->map, res, 1);
    res = my_strcat(res, "3 - 'Necropolis'\n");
    add_stair(&game->map, res, 2);
    res = my_strcat(res, "4 - 'Catacomb'\n");
    add_stair(&game->map, res, 3);
    res = my_strcat(res, "5 - 'Utero'\n");
    add_stair(&game->map, res, 4);
    write_file("assets/save_map.rpg", res, 1);
    if (res) free(res);
    return (0);
}
