/*
** EPITECH PROJECT, 2020
** My Str Low Case
** File description:
** Puts every letter of a string to lowercase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    return (str);
}
