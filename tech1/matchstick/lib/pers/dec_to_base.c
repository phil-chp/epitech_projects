/*
** EPITECH PROJECT, 2021
** dec_to_base
** File description:
** num is the number to convert
** res should be 0 when calling the function (the resulting num in binary)
** base is the base so 2 for binary
** zero should be -1 when calling the function (this adds zeros at the end)
*/

int append_to_nbr(int number, int to_append);

int my_revnbr(int num);

int dec_to_base(int num, int res, int base, int zero)
{
    int temp;

    temp = num % base;
    num /= base;
    if (zero < 0 && temp == 0) zero *= 10;
    if (zero < 0 && temp != 0) zero *= -1;
    res = append_to_nbr(res, temp);
    if (num > 0)
        res = dec_to_base(num, res, base, zero);
    else {
        res = my_revnbr(res);
        if (zero) res *= zero;
    }
    return (res);
}

int *dec_array_to_base_array(int len, int array[len], int base)
{
    for (int i = 0; i < len; i++)
        array[i] = dec_to_base(array[i], 0, base, -1);
    return (array);
}
