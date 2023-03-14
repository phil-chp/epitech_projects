/*
** EPITECH PROJECT, 2020
** Infin Add
** File description:
** Adds Infinite numbers
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"
#include "include/my.h"

void my_swap_str(char **a, char **b);

void my_get_infin_num1(t_add *calc);

void my_get_infin_num2(t_add *calc);

void my_swap_str(char **a, char **b)
{
    char *memory;

    memory = *a;
    *a = *b;
    *b = memory;
}

t_add *new_calc(t_add *calc, char *num1, char *num2)
{
    calc = malloc(sizeof(t_add));
    calc->sign1 = 0;
    calc->sign2 = 0;
    calc->rest = 0;
    calc->num1 = num1;
    calc->num2 = num2;
    if (my_strlen(num1) < my_strlen(num2)) {
    my_swap_str(&calc->num1, &calc->num2);
    }
    calc->len1 = my_strlen(calc->num1) - 1;
    calc->len2 = my_strlen(calc->num2) - 1;
    calc->result = malloc(sizeof(char *) * calc->len1 + 1);
    return (calc);
}

void addition(t_add *calc)
{
    int i = calc->len1, j = calc->len2, k = 0;

    for (i; i >= 0; i--, k++) {
        if (j < 0)
            calc->result[k] = calc->num1[i] + calc->rest;
        else
            calc->result[k] = calc->num1[i] + calc->num2[j] + calc->rest - '0';
        calc->rest = 0;
        if (calc->result[k] > '9') {
            calc->result[k] -= 10;
            calc->rest = 1;
        }
        if (j >= 0)
            j--;
    }
    if (calc->rest == 1)
        calc->result[k] = '1';
    calc->result = my_revstr(calc->result);
    return;
}

void substraction(t_add *calc)
{
    int i = my_strlen(calc->num1) - 1, j = my_strlen(calc->num2) - 1, k = 0;

    for (i; i >= 0; i--, k++) {
        if (j < 0) {
            calc->result[k] = calc->num1[i] - calc->rest;
        } else
            calc->result[k] = calc->num1[i] - calc->num2[j] + calc->rest + 48;
        calc->rest = 0;
        if (calc->result[k] < '0') {
            calc->result[k] += 10;
            calc->rest = 9;
        }

        (j >= 0) && (j--);
    }
    if (calc->rest == 1)
        calc->result[k] = '1';
    while (calc->result[k] == 0)
        k--;
    if (calc->sign1 == 1 && calc->result[k] != '0') {
        calc->result[k] = '-';
        calc->result[k + 1] = '\0';
    } else
        calc->result[k] = '\0';
    calc->result = my_revstr(calc->result);
    return;
}

int main(int ac, char *av[])
{
    t_add *calc;

    if (ac != 3) {
        my_putstr("Wrong Parameters");
        return (0);
    }
    calc = new_calc(calc, av[1], av[2]);
    if ((calc->num1[0] == '-' && calc->num2[0] != '-') &&
        (calc->num1[0] == '-' && calc->num1[0] == '-'))
        my_get_infin_num1(calc);
    if (calc->num2[0] == '-' && calc->num1[0] != '-')
        my_get_infin_num2(calc);
    if (calc->sign1 == 0 && calc->sign2 == 0)
        addition(calc);
    else
        substraction(calc);
    my_putstr(calc->result);
    my_putchar('\n');
    free(calc);
    return (0);
}
