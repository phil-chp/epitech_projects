/*
** EPITECH PROJECT, 2022
** PDG-D4-AM (Workspace)
** File description:
** uniq
*/

#include <string.h>

static void check_if_equal(size_t i, size_t *j, int *array, size_t *nmemb)
{
    if (array[i] == array[*j]) {
        for (size_t k = *j; k < *nmemb; k++)
            array[k] = array[k + 1];
        (*nmemb)--;
        (*j)--;
    }
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    size_t i;

    for (i = 0; i < nmemb; i++) {
        for (size_t j = i + 1; j < nmemb; j++) {
            check_if_equal(i, &j, array, &nmemb);
        }
    }
    return (i);
}

static void check_if_uniq(void *array, size_t *nmemb, size_t size, size_t *j)
{
    for (size_t k = *j; k < *nmemb; k++) {
        memcpy(array + (k * size), array + ((k + 1) * size), size);
    }
    (*nmemb)--;
    (*j)--;
}

size_t uniq_array(void *array, size_t nmemb, size_t size,   \
                            int (*compar) (const void *, const void *))
{
    size_t i;

    for (i = 0; i < nmemb; i++) {
        for (size_t j = i + 1; j < nmemb; j++) {
            void *a = array + (i * size);
            void *b = array + (j * size);
            if (compar(a, b) == 0) check_if_uniq(array, &nmemb, size, &j);
        }
    }
    return (i);
}
