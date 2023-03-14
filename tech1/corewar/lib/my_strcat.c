/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Task 02
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    for (; dest[i]; i++);
    for (int j = 0; src[j]; i++, j++)
        dest[i] = src[j];
    dest[i] = '\0';
    return (dest);
}
