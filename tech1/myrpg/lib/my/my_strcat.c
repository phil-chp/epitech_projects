/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** my_strcat.c
*/

char *my_strcat(char *dest, char *src)
{
    int len_dest = 0;
    int i = 0;

    for (; dest[len_dest]; len_dest++);
    for (; src[i]; len_dest++, i++)
        dest[len_dest] = src[i];
    dest[len_dest] = 0;
    return (dest);
}
