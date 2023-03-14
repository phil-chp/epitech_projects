/*
** EPITECH PROJECT, 2020
** My Rev Syt
** File description:
** Reverses Strings
*/

void my_putchar(char c);

char *my_revstr(char *str)
{
    int i = 0;
    int n = 0;
    int j;
    char mem;

    while (str[i] != '\0')
        i++;
    j = i;
    i--;
    while (n < i) {
        mem = str[n];
        str[n] = str[i];
        str[i] = mem;
        n++;
        i--;
    }
    str[j] = '\0';
    return (str);
}
