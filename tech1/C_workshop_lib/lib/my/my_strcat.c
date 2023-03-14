/*
** EPITECH PROJECT, 2020
** My Str Cat
** File description:
** Concatenates Strings
*/

char *my_strcat(char *dest, char const *src)
{
    int n;

    for (n = 0; dest[n]; n++);
    for (int a = 0; src[a]; a++, n++)
        dest[n] = src[a];
    dest[n] = '\0';
    return (dest);
}

