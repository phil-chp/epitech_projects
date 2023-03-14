/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_pow
** returns a ^ b
*/

int my_pow(int a, int b)
{
    int res;

    res = a;
    for (int i = 0; i < b - 1; i++)
        res *= a;
    return (res);
}
