/*
** EPITECH PROJECT, 2020
** My Get Number
** File description:
** Gets any String and Outputs a Correct Integer
*/

int my_getnbr(char const *str)
{
    int sign = 1;
    int n;
    int number = 0;
    for (n = 0; str[n] != '\0' && (str[n] <= '0' || str[n] > '9'); n++) {
        if (str[n] == '-')
            sign = sign * -1;
    }
    if (str[n] == '\0')
        return (0);
    for (int nbr_char = 0; str[n] != '\0' &&
    (str[n] <= '9' && str[n] >= '0'); n++, nbr_char++) {
        if (((number == 214748364 && str[n] - 48 > 7) || number > 214748364  \
        || nbr_char > 10) && (sign == 1 || (sign == -1 && str[n] - 48 > 8)))
            return (0);
        number = number * 10 + (str[n] - '0');
    }
    return (number * sign);
}
