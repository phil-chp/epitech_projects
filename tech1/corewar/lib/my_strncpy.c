/*
** EPITECH PROJECT, 2020
** put_nbr
** File description:
** output a number
*/

char *my_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i = 0;

    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
