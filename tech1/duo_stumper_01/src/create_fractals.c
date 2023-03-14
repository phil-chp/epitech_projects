/*
** EPITECH PROJECT, 2021
** fractals
** File description:
** create_fractals
*/

#include "fractals.h"
#include "my.h"

#include <stdio.h>

static char check_state(int j, int k)
{
    float x = (float)(j / 3);
    float y = (float)(k / 3);

    if ((x > 1.0 && x < 2.0) || (y > 1.0 && y < 2.0))
        return (1);
    return (0);
}

static int my_arrays_len(char **array)
{
    int i = 0;

    for (i = 0; array[i]; i++);
    return (i);
}

int create_fractals(char **av, int nbr)
{
    char ***strs;
    int *lens;

    strs = malloc(sizeof(char **) * 2);
    lens = malloc(sizeof(int) * 2);
    
    strs[0] = my_str_to_word_array(av[2]);
    strs[1] = my_str_to_word_array(av[3]);
    lens[0] = my_arrays_len(strs[0]);
    lens[1] = my_arrays_len(strs[1]);
    if (nbr != 2) nbr *= nbr;
    for (int k = 0; k < nbr; k++) {
        for (int i = 0; i < lens[0]; i++) {
            for (int j = 0; j < nbr; j++) {
                if ((check_state(j, k) == 1) || (j % 2 == 1 && k % 2 == 1))
                    my_putstr(strs[1][i]);
                else
                    my_putstr(strs[0][i]);
            }
            my_putchar('\n');
        }
    }
    return (0);
}
