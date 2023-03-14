/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_pow
*/

int my_pow(int a, int b)
{
    int res = 0;
    
    for (int i = 0; i < b; i++)
        res += a * a;
    return (res);
}
