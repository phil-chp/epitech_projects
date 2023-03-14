/*
** EPITECH PROJECT, 2020
** big
** File description:
** bs_ant
*/

#include <stdbool.h>
#include <stdlib.h>

bool is_space(char c, char *spaces)
{
    for (int i = 0; spaces[i] != '\0'; i++)
        if (c == spaces[i] || c == '\0')
            return (true);
    return (false);
}

int n_words(char *str, char *spaces)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (is_space(str[i], spaces) == false)
            nb++;
        while (str[i] && is_space(str[i], spaces) == false)
            i++;
        if (str[i] != '\0')
            i++;
    }
    return (nb);
}

int len_word(char const *str, int i, char *spaces)
{
    int len = 0;

    while (is_space(str[i], spaces) == false) {
        i++;
        len++;
    }
    return (len);
}

char **my_str_to_word_array(char *str, char *spaces)
{
    char **tab = malloc(sizeof(char *) * (n_words(str, spaces) + 1));
    int i = 0;
    int j = 0;
    int a = 0;

    for (;j != n_words(str, spaces) && str[i] != '\0'; j++) {
        a = 0;
        while (is_space(str[i], spaces) == true)
            i++;
        tab[j] = malloc(sizeof(char) * (len_word(str, i, spaces) + 1));
        while (is_space(str[i], spaces) == false) {
            tab[j][a] = str[i];
            a++;
            i++;
        }
        tab[j][a] = '\0';
    }
    if (j == 0) return (NULL);
    tab[j] = NULL;
    return (tab);
}
