/*
** EPITECH PROJECT, 2021
** duostumper2
** File description:
** array_dup
*/

#include "gameoflife.h"

char **array_dup(char **map)
{
    char **temp;
    int i = 0;

    temp = malloc(sizeof(char *) * (length_array(map) + 1));
    for (; map[i]; i++)
        temp[i] = strdup(map[i]);
    temp[i] = NULL;
    return (temp);
}
