/*
** EPITECH PROJECT, 2020
** My Str Capitalize
** File description:
** Capitalizes ony the first letter so words
*/

#include <stdio.h>

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    str = my_strlowcase(str);
    if (str[0] >= 97 && str[0] <= 122)
        str[0] -= 32;
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i - 1] == ' ' || str[i - 1] == '-' || str[i - 1] == '+') &&
        (str[i] >= 97 && str[i] <= 122))
            str[i] -= 32;
    return (str);
}
