/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** my_put_tbl
*/

#include <stdio.h>

void my_putchar(char);

int my_putstr(char const *);

void my_put_tbl(const char **tbl)
{
    for (int i = 0; tbl[i]; i++) {
        my_putstr(tbl[i]);
        my_putchar('\n');
    }
    return;
}
