/*
** EPITECH PROJECT, 2021
** solostumper02
** File description:
** palindrome
*/

#include "includes/utils.h"
#include "includes/my.h"

static int palindrome_check(char *word, int len)
{
    for (int i = 0; word[i] && word[len] && i < len; i++, len--)
        if (word[i] != word[len]) return (NOT_PAL);
    return (SUCCESS_CODE);
}

int palindrome(char *word)
{
    int is_palindrome;
    int len;

    word = my_strlowcase(word);
    len = my_strlen(word);
    is_palindrome = palindrome_check(word, len - 1);
    return (is_palindrome);
}
