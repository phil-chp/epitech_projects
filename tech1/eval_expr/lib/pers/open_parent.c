/*
** EPITECH PROJECT, 2020
** Open Parent
** File description:
** Searches for an opening parenthesis
*/

int compare(char *a, char *b);

int open_parent(char **T)
{
    int i = 0;
    int opener = 0;

    while (T[i])
        i++;
    i--;
    while (i > 0) {
        if (compare(T[i], "(") == 1) {
            opener = i;
            return (opener);
        }
        i--;
    }
    return (opener);
}
