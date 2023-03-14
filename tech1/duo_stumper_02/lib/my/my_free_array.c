/*
** EPITECH PROJECT, 2021
** duostumper2
** File description:
** my_free_array
*/

#include <stdlib.h>

void my_free_array(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        if (tab[i]) free(tab[i]);
        tab[i] = NULL;
    }
    if (tab) free(tab);
    tab = NULL;
}
