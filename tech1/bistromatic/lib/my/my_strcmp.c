/*
** EPITECH PROJECT, 2020
** My Str Cmp
** File description:
** Compares two strings together
*/

int my_strcmp(char const *s1, char const *s2)
{
    int a;
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    a = (s1[i] - s2[i]);
    return (a);
}
