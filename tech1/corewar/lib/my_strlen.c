/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(const char *str)
{
    register int i = 0;
    for (;str[i] != '\0'; i++);
    return i;
}

int my_strlen_n(const char *str, char c)
{
    register int i = 0;
    for (;str[i] != c; i++);
    return i;
}

int my_tablen(char **tab)
{
    register int i = 0;

    for (;tab[i]; i++);
    return i;
}
