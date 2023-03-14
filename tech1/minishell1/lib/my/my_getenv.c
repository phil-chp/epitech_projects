/*
** EPITECH PROJECT, 2021
** minishell1 (Workspace)
** File description:
** given a key and a position it will give of the rest of the string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_getenv(char *key, int pos)
{
    int len, i;
    char *value;

    len = my_strlen(key);
    value = malloc(sizeof(char) * (len - pos + 1));
    if (!value) return (NULL);
    for (i = 0; key[pos]; i++, pos++)
        value[i] = key[pos];
    return (value);
}
