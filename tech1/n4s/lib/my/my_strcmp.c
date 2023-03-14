/*
** EPITECH PROJECT, 2020
** My Str Cmp
** File description:
** Compares two Strings and Returns According Int
*/

int my_strcmp(char const *s1 , char const *s2)
{
    int i = 0;

    if (!s1 || !s2) return (0);
    for (; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}
