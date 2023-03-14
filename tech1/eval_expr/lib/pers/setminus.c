/*
** EPITECH PROJECT, 2020
** setminus
** File description:
** set
*/
#include <unistd.h>
#include <stdlib.h>
#include "mymac.h"
#include "my.h"
#include "pers.h"

char *setminus(char *str)
{
    int i = 0;
    char *str2;

    str2 = malloc(sizeof(char) * (my_strlen(str) + 3));
    str = my_revstr(str);
    while (str[i] != '\0') {
        str2[i] = str[i];
        i++;
    }
    str2[i] = '-';
    str2[i + 1] = '\0';
    my_revstr(str2);
    return (str2);
}
