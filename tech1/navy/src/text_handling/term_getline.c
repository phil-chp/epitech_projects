/*
** EPITECH PROJECT, 2020
** Personal Lib
** File description:
** gets user input
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char  const *str);

char *term_getline(void)
{
    char *output;
    size_t size;

    size = 32;
    output = malloc(sizeof(char) * size);
    if (output == NULL) return (NULL);
    if ((getline(&output, &size, stdin)) == -1) return (NULL);
    size = my_strlen(output);
    output[size - 1] = '\0';
    return (output);
}
