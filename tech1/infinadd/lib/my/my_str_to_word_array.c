/*
** EPITECH PROJECT, 2020
** My str to word array
** File description:
** From String creates a word array
*/

#include <stdlib.h>
#include <stddef.h>

int my_putstr(char const *str);

void my_putchar(char c);

char **mem_alloc_str(char const *str)
{
    char **my_array;
    int my_strings = 0, word_check = 0;
    for (int i = 0; str[i] != '\0' ; ){
        word_check = 0;
        for ( ; (str[i] >= 48 && str[i] <= 57) ||
        (str[i] >= 65 && str[i] <= 90) ||
        (str[i] >= 97 && str[i] <= 122); i++)
            word_check = 1;
        if (str[i] != '\0')
            i++;
        if (word_check == 1)
            my_strings++;
    }
    my_array = malloc(sizeof(char *) * (my_strings + 1));
    return (my_array);
}

char **mem_alloc_char(char const *str)
{
    char **my_array = mem_alloc_str(str);
    int my_chars = 0, j = 0, word_check = 0;
    for (int i = 0; str[i] != '\0' ; ){
        my_chars = 0;
        word_check = 0;
        for ( ; (str[i] >= 48 && str[i] <= 57) ||
        (str[i] >= 65 && str[i] <= 90) ||
        (str[i] >= 97 && str[i] <= 122); i++, my_chars++)
            word_check = 1;
        if (str[i] != '\0')
            i++;
        if (word_check == 1) {
            my_array[j] = malloc(my_chars + 1);
            j++;
        }
    }
    return (my_array);
}

char **my_str_to_word_array(char const *str)
{
    char **my_array = mem_alloc_char(str);
    int n = 0, word_check = 0, j = 0;
    for (int i = 0; str[i] != '\0' ; ) {
        j = 0, word_check = 0;
        for ( ; (str[i] >= 48 && str[i] <= 57) ||
        (str[i] >= 65 && str[i] <= 90) ||
        (str[i] >= 97 && str[i] <= 122); j++, i++) {
            my_array[n][j] = str[i];
            word_check = 1;
        }
        if (str[i] != '\0')
            i++;
        if (word_check == 1) {
            my_array[n][j] = '\0';
            n++;
        }
    }
    my_array[n] = NULL;
    return (my_array);
}
