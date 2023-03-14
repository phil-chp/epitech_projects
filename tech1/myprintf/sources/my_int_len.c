/*
** EPITECH PROJECT, 2020
** My int len
** File description:
** My int len
*/

int my_int_len(int num)
{
    int i = !num;
    for (i; num > 9; ++i)
        num /= 10;
    return (i + 1);
}