/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** my_putstr
*/

#include <unistd.h>

int my_strlen(char *str);

int my_putstr(char *str)
{
    return (write(1, str, my_strlen(str)));
}

int my_putstr_len(char *str, int len)
{
    return (write(1, str, len));
}
