/*
** EPITECH PROJECT, 2020
** my Put Str
** File description:
** Displays Chars Ony by One
*/

void my_putchar(char c);

void my_putstr(char *str)
{
    int c = 0;

    while (str[c] != '\0') {
        my_putchar(str[c]);
        c++;
    }
    return;
}