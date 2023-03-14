/*
** EPITECH PROJECT, 2020
** Close Parent
** File description:
** Finds the closing parenthesis
*/

int compare(char *a, char *b);

int open_parent(char **T);

int close_parent(char **T)
{
    int i = 0;
    int j = 0;
    int ender = 0;

    while (T[i])
        i++;
    j = open_parent(T);
    while (j < i) {
        if (compare(T[j], ")") == 1) {
            ender = j;
            return (ender);
        }
        j++;
    }
    return (ender);
}
