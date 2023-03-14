/*
** EPITECH PROJECT, 2021
** antman
** File description:
** check if one element is already known and 'add it' or '+1 it'
*/

#include <stdlib.h>
#include "../include/assets.h"
#include "../include/my.h"

void check_word(char *temp, buff_t *buff)
{
    int count = 0;
    int i;
    if (buff->check == 1)
        add_new_word(temp, buff);
    for (i = 0; buff->array[i]; i++)
        if (my_strcmp(temp, buff->array[i]) == 0)
            count++;
    if (count == 0)
        add_new_word(temp, buff);
    else
        add_plus_one(temp, buff);
}
