/*
** EPITECH PROJECT, 2020
** Infin Functions
** File description:
** Functions for the Infin Add project
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"
#include "include/my.h"

void my_get_infin_num1(t_add *calc)
{
    int sign = 1, n, m = 0;

    for (n = 0; calc->num1[n] != '\0' && (calc->num1[n] <= '0'
    || calc->num1[n] > '9'); n++) {
        if (calc->num1[n] == '-')
            sign *= -1;
    }
    if (sign == -1) {
        calc->sign1 = 1;
    }
    for (int nbr_char = 0; calc->num1[n] != '\0' &&
    (calc->num1[n] >= '0' && calc->num1[n] <= '9');
    m++, n++, nbr_char++) {
        calc->num1[m] = calc->num1[n];
    }
    calc->num1[m] = '\0';
    return;
}

void my_get_infin_num2(t_add *calc)
{
    int sign = 1, n, m = 0;

    for (n = 0; calc->num2[n] != '\0' && (calc->num2[n] <= '0'
    || calc->num2[n] > '9'); n++) {
        if (calc->num2[n] == '-')
            sign *= -1;
    }
    if (sign == -1) {
        calc->sign2 = 1;
    }
    for (int nbr_char = 0; calc->num2[n] != '\0' &&
    (calc->num2[n] >= '0' && calc->num2[n] <= '9');
    m++, n++, nbr_char++) {
        calc->num2[m] = calc->num2[n];
    }
    if (calc->num1[0] == '-' && calc->num1[0] != '-') {
        my_swap_str(&calc->num1, &calc->num2);
    }
    calc->num2[m] = '\0';
    return;
}
