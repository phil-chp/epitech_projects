/*
** EPITECH PROJECT, 2020
** My Str Is Printable
** File description:
** Checks if string is only printable characters
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 32)
            return (0);
    return (1);
}
