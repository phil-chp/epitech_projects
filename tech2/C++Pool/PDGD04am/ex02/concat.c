/*
** EPITECH PROJECT, 2022
** PDG-D4-AM (Workspace)
** File description:
** main
*/

#include <stdlib.h>
#include "concat.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

void concat_strings(const char *str1, const char *str2, char **res)
{
    int n = 0;
    int size = 0;
    char *my_res = NULL;

    size = my_strlen(str1) + my_strlen(str2) + 1;
    my_res = malloc(sizeof(char) * size);
    for (; str1[n]; n++) {
        my_res[n] = str1[n];
    }
    for (int a = 0; str2[a]; a++, n++)
        my_res[n] = str2[a];
    my_res[n] = '\0';
    *res = my_res;
}

void concat_struct(concat_t *str)
{
    int n = 0;
    int size = 0;
    char *my_res = NULL;

    size = my_strlen(str->str1) + my_strlen(str->str2) + 1;
    my_res = malloc(sizeof(char) * size);
    for (; str->str1[n]; n++) {
        my_res[n] = str->str1[n];
    }
    for (int a = 0; str->str2[a]; a++, n++)
        my_res[n] = str->str2[a];
    my_res[n] = '\0';
    str->res = my_res;
}
