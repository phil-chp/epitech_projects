/*
** EPITECH PROJECT, 2020
** My String N Copy
** File description:
** Copies a Part of a String into Another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i++)
        dest[i] = src[i];
    return (dest);
}
