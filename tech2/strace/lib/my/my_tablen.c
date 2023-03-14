/*
** EPITECH PROJECT, 2022
** strace (Workspace)
** File description:
** my_tablen
*/

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i]; ++i);
    return (i);
}
