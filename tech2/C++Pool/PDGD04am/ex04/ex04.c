/*
** EPITECH PROJECT, 2022
** PDG-D4-AM (Workspace)
** File description:
** my_lib
*/

char *my_revstr(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    i--;
    for (int n = 0; n < i; n++, i--) {
        char mem = str[n];
        str[n] = str[i];
        str[i] = mem;
    }
    return (str);
}

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    return (str);
}
