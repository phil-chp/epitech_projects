/*
** EPITECH PROJECT, 2020
** My String Copy
** File description:
** Copies a String into Another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
