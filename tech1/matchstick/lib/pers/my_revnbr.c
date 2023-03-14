/*
** EPITECH PROJECT, 2021
** my_revnbr
** File description:
** reverses an int
*/

int my_revnbr(int num)
{
    int res = 0;

    for (; num > 0; num /= 10)
        res = (res * 10) + (num % 10);
    return (res);
}
