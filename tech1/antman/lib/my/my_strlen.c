/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** Counts String Length
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i]; i++);
    return (i);
}
