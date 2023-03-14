/*
** EPITECH PROJECT, 2022
** PDG-D4-AM (Workspace)
** File description:
** mul_div
*/

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    *div = (b == 0 ? 42 : a / b);
}

void mul_div_short(int *a , int *b)
{
    int mem_a = 0;
    int mem_b = 0;

    mem_a = *a * *b;
    mem_b = (*b == 0 ? 42 : *a / *b);
    *a = mem_a;
    *b = mem_b;
}
