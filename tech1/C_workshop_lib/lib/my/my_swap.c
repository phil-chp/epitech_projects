/*
** EPITECH PROJECT, 2020
** My Swap
** File description:
** Swaps variables
*/

void my_swap(int *a, int *b)
{
    int memory;

    memory = *a;
    *a = *b;
    *b = memory;
}
