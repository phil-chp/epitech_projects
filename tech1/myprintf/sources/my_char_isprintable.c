/*
** EPITECH PROJECT, 2020
** My char is printable
** File description:
** My char is printable
*/

int my_char_isprintable(char const ch)
{
    if (ch < 32 || ch > 126)
            return (0);
    return (1);
}