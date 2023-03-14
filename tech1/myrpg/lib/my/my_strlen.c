/*
** EPITECH PROJECT, 2020
** My String Length
** File description:
** Counts String Length
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    size_t i = 0;

    for (; str[i]; i++);
    return (i);
}
