/*
** EPITECH PROJECT, 2020
** Change T Crush
** File description:
** Removes parenthesis
*/

char **change_tcrush(int pos, char **T)
{
    while (T[pos + 3]) {
        T[pos - 1] = T[pos + 3];
        pos++;
    }
    T[pos - 1] = 0;
    return (T);
}
