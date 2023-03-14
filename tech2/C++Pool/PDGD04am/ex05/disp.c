/*
** EPITECH PROJECT, 2022
** PDG-D4-AM (Workspace)
** File description:
** sort_bis
*/

#include <stdio.h>

void disp_array(const void *array, size_t nmemb, size_t size,   \
                            void (*print) (const void *))
{
    for (size_t i = 0; i < nmemb; i++) {
        printf(" ");
        print(array + (i * size));
    }
}

void disp_int_array(const int *array, size_t nmemb)
{
    for (size_t i = 0; i < nmemb; i++) {
        printf("%d ", array[i]);
    }

}
