/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** my_strlen
*/

int my_strlen(char  const *str)
{
    int c;

    for (c = 0; str[c] != '\0'; c++);
    return (c);
}
