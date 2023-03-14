/*
** EPITECH PROJECT, 2020
** my personal lib
** File description:
** Sorts a int * list and a char ** list using bubble sort
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/assets.h"
#include "../include/my.h"

static void swap_elem(int *ints, char **strs, int a, int b)
{
    if (!strs) {
        int temp = ints[a];
        ints[a] = ints[b];
        ints[b] = temp;
    } else {
        char *temp = my_strdup(strs[a]);
        free(strs[a]);
        strs[a] = my_strdup(strs[b]);
        free(strs[b]);
        strs[b] = my_strdup(temp);
        free(temp);
    }
}

void bubble_sort_array(int size, buff_t *buff)
{
    int swaps;

    swaps = 1;
    for (int i = 0; swaps != 0; i++) {
        if (buff->rep[i] < buff->rep[i + 1]) {
            swap_elem(buff->rep, NULL, i, i + 1);
            swap_elem(NULL, buff->array, i, i + 1);
            swaps++;
        }
        if (i + 1 >= size - 1 && swaps != 0) {
            swaps = (swaps == 1) ? (0) : (1);
            i = -1;
        }
    }
}
