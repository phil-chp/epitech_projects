/*
** EPITECH PROJECT, 2022
** PDG-D4-AM (Workspace)
** File description:
** main
*/

#include <stdio.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res);

void array_2d_free(int **array, size_t height, size_t width);

int main(void)
{
    int **array_2d;
    const int array_1d[42] = {
        0,  1,  2,  3,  4,  5,
        6,  7,  8,  9,  10, 11,
        12, 13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23,
        24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35,
        36, 37, 38, 39, 40, 41
    };

    array_1d_to_2d(array_1d, 7, 6, &array_2d);
    printf("array_2d[%d][%d] = %d\n", 0, 0, array_2d[0][0]);
    printf("array_2d[%d][%d] = %d\n", 6, 5, array_2d[6][5]);
    printf("array_2d[%d][%d] = %d\n", 4, 4, array_2d[4][4]);
    printf("array_2d[%d][%d] = %d\n", 0, 3, array_2d[0][3]);
    printf("array_2d[%d][%d] = %d\n", 3, 0, array_2d[3][0]);
    printf("array_2d[%d][%d] = %d\n", 4, 2, array_2d[4][2]);
    array_2d_free(array_2d, 7, 6);
    return (0);
}
