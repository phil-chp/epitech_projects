/*
** EPITECH PROJECT, 2020
** My Is Alpha
** File description:
** Checks if String Is Alphabetical
*/

#include <stdio.h>

int  my_str_isalpha(char  const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
            return (0);
    return (1);
}
