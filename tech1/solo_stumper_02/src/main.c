/*
** EPITECH PROJECT, 2021
** solostumper02
** File description:
** main
*/

#include "includes/utils.h"
#include "includes/my.h"

int main(int ac, char **av)
{
    int is_palindrome;

    if (ac != 2) {
        BAD_ARGS;
        return (ERROR_CODE);
    }
    is_palindrome = palindrome(av[1]);
    if (is_palindrome == NOT_PAL)
        my_putstr("not a palindrome.\n");
    else
        my_putstr("palindrome!\n");
    return (SUCCESS_CODE);
}
