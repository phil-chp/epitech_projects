/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** my_is_alpha_numerical
*/

int isalphanum(char const c)
{
    return ((c < 'A' || c > 'Z')
    &&      (c < 'a' || c > 'z')
    &&      (c < '0' || c > '9'));
}
