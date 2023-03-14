/*
** EPITECH PROJECT, 2020
** Checksec
** File description:
** Checks for addition and substraction
*/

int compare(char *a, char *b);

int checksec(char **T, int open, int close)
{
    int i = open;

    while (i < close) {
        if (compare(T[i], "+") == 1 || compare(T[i], "-") == 1)
            return (i);
        i++;
    }
    return (0);
}
