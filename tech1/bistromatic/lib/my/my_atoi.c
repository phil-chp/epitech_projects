/*
** EPITECH PROJECT, 2020
** My Atoi
** File description:
** Returns a number from a string
*/

int my_atoi(char const *str)
{
    int i = 0;
    int neg = 1;
    int nbr = 0;

    if (str[0] == '-') {
        neg -= 2;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            nbr = (nbr * 10) + (str[i] - 48);
            i++;
        }
        else if (str[i] != '\0')
            return (neg * nbr);
    }
    return (neg * nbr);
}