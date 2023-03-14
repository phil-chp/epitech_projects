/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** my_str_to_int_array.c
*/

#include <stdbool.h>
#include <stdlib.h>

int my_getnbr(char const *str);

char **my_str_to_word_array_div(char *str, char div);

bool my_str_to_int_array(int **dest, char *src, char split)
{
    char **array;
    int i;

    if (!((*dest) = malloc(sizeof(int) * 13)))
        return (1);
    if (!(array = my_str_to_word_array_div(src, split)))
        return (1);
    for (i = 0; array[i]; i++) {
        int temp = my_getnbr(array[i]);
        (*dest)[i] = temp;
    }
    (*dest)[i] = 0;
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    return (0);
}
