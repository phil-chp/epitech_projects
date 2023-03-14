/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** my_put_tbl
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char);

int my_putstr(char const *);

void my_put_tbl(const char **tbl)
{
    for (int i = 0; tbl[i]; i++)
        my_putstr(tbl[i]);
}
