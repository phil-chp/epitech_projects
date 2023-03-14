/*
** EPITECH PROJECT, 2020
** Change T
** File description:
** Changes the positions of the table.
*/

char **change_t(int pos, char **T)
{
    while (T[pos + 2]) {
        T[pos] = T[pos + 2];
        pos++;
    }
    T[pos] = 0;
    return (T);
}
