/*
** EPITECH PROJECT, 2022
** PDG-D4-AM (Workspace)
** File description:
** sort
*/

#include <stdlib.h>

static void is_sorted(int i, int j, int *array)
{
    if (array[i] > array[j]) {
        int mem = array[i];
        array[i] = array[j];
        array[j] = mem;
    }
}

void sort_int_array(int *array, size_t nmemb)
{
    for (size_t i = 0; i <= nmemb - 1; i++)
        for (size_t j = i + 1; j <= nmemb - 1; j++)
            is_sorted(i, j, array);
}

void sort_array(void *array, size_t nmemb, size_t size, \
                            int (*compar) (const void *, const void *))
{
    qsort(array, nmemb, size, compar);
}
