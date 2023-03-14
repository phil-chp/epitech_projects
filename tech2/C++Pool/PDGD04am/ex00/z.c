/*
** EPITECH PROJECT, 2022
** PDG-D4-AM
** File description:
** z
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

int my_putstr(char const *str)
{
    return (write(1, str, my_strlen(str)));
}

int main(void)
{
    my_putstr("z\n");
    return (0);
}
