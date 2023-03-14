/*
** EPITECH PROJECT, 2020
** my str is lower
** File description:
** dc
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 122 || str[i] < 97)
            return (0);
        i++;
    }
    return (1);
}
