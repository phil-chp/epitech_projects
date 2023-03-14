/*
** EPITECH PROJECT, 2021
** antman
** File description:
** add +1 for iteration of one element
*/

#include <stdlib.h>
#include <stdlib.h>
#include "../../include/assets.h"
#include "../../include/my.h"

void add_plus_one(char *temp, buff_t *buff)
{
    int i;

    for (i = 0; my_strcmp(buff->array[i], temp) != 0; i++);
    buff->rep[i] += 1;
}
