/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** manage signal (ord & abs) coord.
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"

char *bin_to_dec(char *bin)
{
    char letter[] = "ABCDEFGH";
    char num[] = "12345678";
    char *temp = malloc(sizeof(char) * 3);
    int a1 = (bin[0] - 48) * 4;
    int a2 = (bin[1] - 48) * 2;
    int a3 = (bin[2] - 48) * 1;
    int a4 = (bin[3] - 48) * 4;
    int a5 = (bin[4] - 48) * 2;
    int a6 = (bin[5] - 48) * 1;

    temp[0] = letter[a1 + a2 + a3];
    temp[1] = num[a4 + a5 + a6];
    temp[2] = '\0';
    return (temp);
}

char *dec_to_bin(char *shoot)
{
    int letter = shoot[0] - 65;
    int number = shoot[1] - 49;
    char *ord = malloc(sizeof(char) * 4);
    char *abs = malloc(sizeof(char) * 4);
    char *result = malloc(sizeof(char) * 7);
    int i, j = letter % 2;

    for (i = 0; i != 3; i++, letter /= 2, j = letter % 2)
        ord[i] = j + 48;
    ord[i] = '\0';
    for (i = 0; i != 3; i++, number /= 2, j = number % 2)
        abs[i] = j + 48;
    abs[i] = '\0';
    result = my_revstr(ord);
    result = my_strcat(result, my_revstr(abs));
    return (result);
}
