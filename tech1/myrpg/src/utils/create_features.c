/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** features.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

static void second_part(game_t *game, char **res)
{
    (*res) = my_strcat((*res), my_getstr(game->player.stats.speed));
    (*res) = my_strcat((*res), " ");
    (*res) = my_strcat((*res), my_getstr(game->player.stats.arms));
    (*res) = my_strcat((*res), " ");
    (*res) = my_strcat((*res), my_getstr(game->player.stats.defense));
    (*res) = my_strcat((*res), " ");
    (*res) = my_strcat((*res), my_getstr(game->player.stats.jump));
    (*res) = my_strcat((*res), " ");
    (*res) = my_strcat((*res), my_getstr(game->player.stats.attack));
    (*res) = my_strcat((*res), " ");
    (*res) = my_strcat((*res), my_getstr(game->player.stats.special));
    (*res) = my_strcat((*res), " 2231231");
}

bool create_feature(game_t *game)
{
    char *temp = NULL, *res = NULL;

    if (!(res = malloc(sizeof(char) * 45))) return (1);
    res = my_strcpy(res, my_getstr(game->player.stats.health));
    res = my_strcat(res, " ");
    res = my_strcat(res, my_getstr(game->player.stats.mana));
    res = my_strcat(res, " ");
    res = my_strcat(res, my_getstr(game->player.stats.stars));
    res = my_strcat(res, " ");
    res = my_strcat(res, my_getstr(game->player.stats.keys));
    res = my_strcat(res, " ");
    res = my_strcat(res, my_getstr(game->player.stats.bombs));
    res = my_strcat(res, " ");
    second_part(game, &res);
    res[my_strlen(res)] = '\0';
    write_file("assets/save_stat.rpg", res, 1);
    if (temp) free(temp);
    if (res)  free(res);
    return (0);
}
