/*
** EPITECH PROJECT, 2020
** my showstr
** File description:
** vf
*/
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int  my_putstr(char  const *str);

int  my_strlen(char  const *str);

char lettera(int a)
{
    if (a == 10)
        return 97;
    if (a == 11)
        return 98;
    if (a == 12)
        return 99;
    if (a == 13)
        return 100;
    if (a == 14)
        return 101;
    if (a == 15)
        return 102;
    else
        return (a + 48);
}

int my_showstr(char const *str)
{
    int i = 0, j = 0;
    char *dest;
    dest = malloc((sizeof(char)*(my_strlen(str))*3)+1);
    while (str[i] != '\0') {
        if ((str[i] >= 0 && str[i] < 32) || (str[i] > 127 && str[i] <= 255)) {
            int prem = str[i]/16;
            int sec = str[i]%16;
            dest[j] = '\\';
            dest[j + 1] = lettera(prem);
            dest[j + 2] = lettera(sec);
            j += 2;
        }
        else
            dest[j] = str[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    my_putstr(dest);
    return 0;
}
