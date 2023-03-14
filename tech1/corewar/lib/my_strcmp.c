/*
** EPITECH PROJECT, 2020
** put_nbr
** File description:
** output a number
*/

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] || s2[i]) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}
