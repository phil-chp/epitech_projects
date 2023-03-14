/*
** EPITECH PROJECT, 2022
** Panoramix (Workspace)
** File description:
** utils
*/

#include <stdio.h>

void print_usage(FILE *stream, char *name)
{
    fprintf(stream,                                                        \
        "USAGE: %s <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n",  \
        name);
}

void print_error(char *name, char *message)
{
    fprintf(stderr, "%s: %s\n", name, message);
}
