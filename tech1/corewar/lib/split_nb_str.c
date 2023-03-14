/*
** EPITECH PROJECT, 2020
** temp
** File description:
** split_nb_str.c
*/

#include <stdlib.h>

int my_strlen(char *str);

char *split_nb_str(char *str, int nb)
{
    char *temp;
    int j = 0;
    int len;

    len = my_strlen(str);
    if (!(temp = malloc(sizeof(char) * (len + (len / nb) + nb))))
        return (NULL);
    for (int i = 0; str[i]; i++, j++) {
        temp[j] = str[i];
        if (i % 2 != 0) {
            j += 1;
            temp[j] = ' ';
        }
    }
    temp[j] = '\0';
    return (temp);
}
