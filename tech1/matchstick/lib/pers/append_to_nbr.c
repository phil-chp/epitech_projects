/*
** EPITECH PROJECT, 2021
** pers
** File description:
** append_to_nbr
*/

int my_int_len(int num);

int my_pow(int a, int b);

int append_to_nbr(int number, int to_append)
{
    int len;
    int res;

    len = my_int_len(to_append);
    res = my_pow(10, len) * number;
    res += to_append;
    return (res);
}
