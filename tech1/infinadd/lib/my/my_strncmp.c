/*
** EPITECH PROJECT, 2020
** My Str N Cmp
** File description:
** Compares two Strings and Returns the Difference
*/

int my_strncmp(char const *s1 , char const *s2, int n)
{
    int i;

    while (s1[i] == s2[i] && i < n && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}
