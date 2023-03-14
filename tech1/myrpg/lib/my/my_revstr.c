/*
** EPITECH PROJECT, 2020
** My Rev Syt
** File description:
** Reverses Strings
*/

char *my_revstr(char *str)
{
    char mem = 0;
    int i = 0;

    for (; str[i]; i++);
    i--;
    for (int n = 0; n < i; n++, i--) {
        mem = str[n];
        str[n] = str[i];
        str[i] = mem;
    }
    return (str);
}
