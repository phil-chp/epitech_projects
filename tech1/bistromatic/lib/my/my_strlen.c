/*
** EPITECH PROJECT, 2020
** My Str Len
** File description:
** returns the length of a given string
*/

int my_strlen(char *str)
{
    int c = 0;

    while (str[c] != '\0')
        c++;
    return (c);
}
