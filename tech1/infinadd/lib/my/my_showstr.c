/*
** EPITECH PROJECT, 2020
** My Show Str
** File description:
** Prints strings, even non printable characters in hex
*/

#include <stdio.h>
#include <stdlib.h>

int my_str_isprintable(char const *str);

void my_putstr(char const *str);

int my_strlen(char const *str);

int my_char_isprintable(char const ch)
{
    if (ch < 32)
            return (0);
    return (1);
}

char to_hex(int check, char const *str, int i)
{
    char y = 96;
    int w = 0;

    if (check == 0)
        w = str[i] / 16;
    if (check == 1)
        w = str[i] % 16;
    if (w != 0 && w <= 9)
        y = 48 + w;
    if (w > 9) {
        w -= 9;
        y += w;
    }
    if (w == 0)
        y = 48;
    return (y);
}

int my_showstr(char const *str)
{
    char *result;
    int j = 0;

    result = malloc(sizeof(char) * my_strlen(str) * 3 + 1);
    for (int i = 0; str[i] != '\0'; i++, j++) {
        if (my_char_isprintable(str[i]) == 0) {
            result[j] = '\\';
            result[j + 1] = to_hex(0, str, i);
            result[j + 2] = to_hex(1, str, i);
            j += 3;
            i++;
        }
        result[j] = str[i];
    }
    result[j] = '\0';
    my_putstr(result);
    return (0);
}
