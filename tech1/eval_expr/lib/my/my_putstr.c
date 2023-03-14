/*
** EPITECH PROJECT, 2020
** myputstr
** File description:
** disp str 1-1 char
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


