/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}
