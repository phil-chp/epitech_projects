/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** get_random
*/

#include <stdlib.h>

int get_random(unsigned int min, unsigned int max)
{
    return (rand() % (max + 1 - min) + min);
}
