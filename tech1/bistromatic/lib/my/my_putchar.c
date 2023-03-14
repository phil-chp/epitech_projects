/*
** EPITECH PROJECT, 2020
** My Put Char
** File description:
** Using write functions, outputs a char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
