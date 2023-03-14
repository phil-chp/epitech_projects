/*
** EPITECH PROJECT, 2020
** ret a str with only '-' or nothing
** File description:
** ex s = "- - - 3456" retarg -> - - 3456"
** etc... or " - - - - 345" retarg -> 345
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *retarg(char *nb)
{
    char *str;
    int k, i = 0, nbmoin = 0;
    int a = my_strlen(nb);

    str = malloc(sizeof(char *)*(a + 1));
    for (i; nb[i] == '-' || nb[i] == '+'; i++)
        (nb[i] == '-') ? (nbmoin++) : 0;
    if (nbmoin % 2 == 1) {
        str[0] = '-';
        k = 1;
        for (i; nb[i] != '\0'; k++, i++)
            str[k] = nb[i];
    }
    else {
        k = 0;
        for (i; nb[i] != '\0'; k++, i++)
            str[k] = nb[i];
    }
    str[k] = '\0';
    return (str);
}
