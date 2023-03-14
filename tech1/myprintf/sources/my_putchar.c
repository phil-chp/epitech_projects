/*
** EPITECH PROJECT, 2020
** My Put Char
** File description:
** Uses function write
*/

#include <unistd.h>

int my_putchar(char const c)
{
    return (write(1, &c, 1));
}