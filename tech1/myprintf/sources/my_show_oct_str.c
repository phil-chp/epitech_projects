/*
** EPITECH PROJECT, 2020
** My Show Str
** File description:
** Prints strings, even non printable characters in hex
*/

#include <stdio.h>
#include <stdlib.h>

int my_str_isprintable(char const *str);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_char_isprintable(char const ch);

char str_to_oct(int check, char const *str, int i)
{
    char y = 96;
    int w = 0;

    if (check == 0)
        w = str[i] / 8;
    if (check == 1)
        w = str[i] % 8;
    if (w > 7)
        return (-1);
    if (w != 0 && w <= 9)
        y = 48 + w;
    if (w == 0)
        y = 48;
    return (y);
}

int my_show_oct_str(char const *str)
{
    char res[99999];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++, j++) {
        if (my_char_isprintable(str[i]) == 0) {
            res[j] = '\\';
            res[j + 1] = str_to_oct(0, str, i);
            res[j + 2] = str_to_oct(1, str, i);
            j += 3;
        }
        ((str[i] > 31 && str[i] < 127) || str[i] > 127) ? res[j] = str[i] : j--;
    }
    res[j] = '\0';
    my_putstr(res);
    return (0);
}
