/*
** EPITECH PROJECT, 2020
** My Put String
** File description:
** Decomposes String Characters one-by-one
*/

#include <unistd.h>

int my_strlen(const char *str);

int my_putstr(const char *str)
{
    return (write(1, str, my_strlen(str)));
}
