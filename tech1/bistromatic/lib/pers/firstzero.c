/*
** EPITECH PROJECT, 2020
** First Zero
** File description:
** Adds a zero infront of string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *firstzero(char *str)
{
    char *str2;
    int j = 1;
    int len = my_strlen(str);

    str2 = malloc(sizeof(char) * (len + 2));
    str2[0] = '0';
    for (int i = 0; str[i]; i++, j++) {
        str2[j] = str[i];
    }
    str2[j] = '\0';
    return (str2);
}
