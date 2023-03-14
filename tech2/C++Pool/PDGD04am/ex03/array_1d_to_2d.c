/*
** EPITECH PROJECT, 2022
** PDG-D4-AM
** File description:
** array_1d_to_2d
*/

#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int **my_res = NULL;
    int n = 0;

    my_res = malloc(sizeof(int *) * height);
    for (size_t i = 0; i < height; i++) {
        my_res[i] = malloc(sizeof(int) * width);
        for (size_t j = 0; j < width; j++) {
            my_res[i][j] = array[n++];
        }
    }
    *res = my_res;
}

void array_2d_free(int **array, size_t height, size_t width)
{
    if (width) {}
    for (size_t i = 0; i < height; i++) {
        if (array[i]) {
            free(array[i]);
        }
    }
    if (array) {
        free(array);
    }
}
