/*
** EPITECH PROJECT, 2020
** My Str Dup
** File description:
** Allocates memory and writes string
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_arraylen(char **array);

char *my_strdup(char const *src)
{
    char *str;
    int n = 0;

    str = malloc(sizeof(char) * my_strlen(src) + 1);
    if (!str) return (NULL);
    for (; src[n] != '\0'; n++)
        str[n] = src[n];
    str[n] = '\0';
    return (str);
}

char **my_arraydup(char **src)
{
    char **array;
    int i = 0;

    array = malloc(sizeof(char *) * (my_arraylen(src) + 1));
    if (!array) return (NULL);
    for (; src[i]; i++) {
        array[i] = my_strdup(src[i]);
        if (!array[i]) {
            (array) && (free(array), 0);
            return (NULL);
        }
    }
    array[i] = NULL;
    return (array);
}
