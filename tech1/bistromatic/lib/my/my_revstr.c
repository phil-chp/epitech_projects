/*
** EPITECH PROJECT, 2020
** My Rev Str
** File description:
** reverses a string
*/

char *my_revstr(char *str)
{
    int a = 0;
    int b;
    int q;
    int i = 0;
    char temp;

    while (str[a] != '\0')
        a++;
    b = a;
    q = a / 2;
    a--;
    while (i != q) {
        temp = str[a];
        str[a] = str[i];
        str[i] = temp;
        i++;
        a--;
    }
    return (str);
}