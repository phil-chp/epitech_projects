/*
** EPITECH PROJECT, 2022
** PDG-D4-AM (Workspace)
** File description:
** print_functions
*/

#include <stdio.h>
#include <string.h>
#include "print.h"

int my_putstr(const char *str);

char *my_revstr(const char *str);

char *my_strupcase(const char *str);

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    size_t len = strlen(str);
    char my_str[len];

    for (size_t i = 0; i <= len; i++) {
        my_str[i] = str[i];
    }
    printf("%s\n", my_revstr(my_str));
}

void print_upper(const char *str)
{
    size_t len = strlen(str);
    char my_str[len];

    for (size_t i = 0; i <= len; i++) {
        my_str[i] = str[i];
    }
    printf("%s\n", my_strupcase(my_str));
}

void print_42(const char *str)
{
    if (str) {}
    printf("42\n");
}

void (*my_print[4])(const char *str) = {
    print_normal,
    print_reverse,
    print_upper,
    print_42
};

void do_action(action_t action, const char *str)
{
    my_print[action](str);
}
