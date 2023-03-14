/*
** EPITECH PROJECT, 2020
** My Str N Cmp
** File description:
** Compares two Strings and Returns the Difference
*/

int my_strncmp(char const *s1 , char const *s2, int n)
{
    int i;

    for (i = 0; s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i]; i++);
    return (s1[i] - s2[i]);
}
