/*
** EPITECH PROJECT, 2021
** antman
** File description:
** initializes the structure
*/

#include <stdlib.h>
#include "../../include/assets.h"
#include "../../include/my.h"

int nb_word(char *file_str, int step)
{
    int count = 0;
    int i = 0;

    if (step == A_STEP) {
        for (; file_str[i + 1]; i++)
            ((file_str[i] != ' ' && file_str[i] != '\n') \
                && (file_str[i + 1] == ' ' || file_str[i + 1] == '\n')) \
                && (count++, 0);
        return (count + 2);
    } else {
        while (file_str[i] != '\a' && file_str[i + 1] != '\a')
            i++;
        return (i);
    }
}

buff_t *init_buff(char *file_str, int step)
{
    buff_t *buff;
    int j = -1, i;

    buff = malloc(sizeof(buff_t));
    if (!buff) return (NULL);
    if (step == A_STEP)
        j = my_strlen(file_str);
    i = nb_word(file_str, step);
    buff->check = (step == A_STEP) ? (1) : (0);
    buff->rep = malloc(sizeof(int) * (j + 2));
    buff->array = malloc(sizeof(char *) * i);
    buff->file_content = my_strdup(file_str);
    if (!buff->rep || !buff->array) {
        free(buff);
        return (NULL);
    }
    if (step == G_STEP)
        buff->rep[0] = 0;
    return (buff);
}
