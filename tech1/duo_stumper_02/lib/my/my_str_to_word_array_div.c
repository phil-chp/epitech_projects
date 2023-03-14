/*
** EPITECH PROJECT, 2020
** My str to word array div
** File description:
** From String creates a word array separated by given char
*/

#include <stdlib.h>

static char **mem_alloc_str(char const *str, char div)
{
    int my_strings = 1;
    int word_check = 0;
    char **my_array;

    for (int i = 0; str[i]; ){
        word_check = 0;
        for (; str[i] >= 33 && str[i] <= 126    \
                && str[i] != div; i++, word_check = 1);
        if (str[i]) i++;
        if (word_check == 1) my_strings++;
    }
    my_array = malloc(sizeof(char *) * (my_strings + 1));
    return (my_array);
}

static char **mem_alloc_char(char const *str, char div)
{
    int word_check = 0;
    int my_chars = 1;
    char **my_array;
    int j = 0;

    my_array = mem_alloc_str(str, div);
    for (int i = 0; str[i]; ){
        my_chars = 0;
        word_check = 0;
        for (; str[i] >= 33 && str[i] <= 126    \
                && str[i] != div; i++, my_chars++, word_check = 1);
        if (str[i]) i++;
        if (word_check == 1) {
            my_array[j] = malloc(my_chars + 1);
            j++;
        }
    }
    return (my_array);
}

char **my_str_to_word_array_div(char const *str, char div)
{
    int word_check = 0;
    char **my_array;
    int n = 0;
    int j = 0;

    my_array = mem_alloc_char(str, div);
    for (int i = 0; str[i]; ) {
        j = 0, word_check = 0;
        for (; str[i] >= 33 && str[i] <= 126  \
                && str[i] != div; j++, i++, word_check = 1)
            my_array[n][j] = str[i];
        if (str[i]) i++;
        if (word_check == 1) {
            my_array[n][j] = '\0';
            n++;
        }
    }
    my_array[n] = NULL;
    return (my_array);
}
