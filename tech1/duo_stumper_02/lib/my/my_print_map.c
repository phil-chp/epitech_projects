/*
** EPITECH PROJECT, 2021
** duostumper2
** File description:
** my_print_map
*/

#include <stdio.h>

void my_print_map(char **map)
{
    for (int i = 0; map[i]; i++)
        printf("%s\n", map[i]);
}
