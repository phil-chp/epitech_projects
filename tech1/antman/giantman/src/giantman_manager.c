/*
** EPITECH PROJECT, 2021
** antman
** File description:
** Handles the entire giantman project
*/

#include <stdlib.h>
#include <stdlib.h>
#include "../../include/assets.h"
#include "../../include/my.h"

void r_add_word(char *temp, buff_t *buff)
{
    int i = 0;

    if (buff->check == 1) {
        buff->array[0] = my_strdup(temp);
        return;
    }
    for (; buff->array[i]; i++);
    buff->array[i] = my_strdup(temp);
    buff->array[i + 1] = NULL;
}

buff_t *giantman_manager(char *file_str)
{
    int start = 0;
    buff_t *buff;
    int i = 0;

    buff = init_buff(file_str, G_STEP);
    for (; buff->file_content[i + 1] && buff->file_content[i] != '\a'    \
                                && buff->file_content[i + 1] != '\a'; i++) {
        for (; IS_NOT_SEPARATOR && FILE_EXISTS; i++);
        for (; IS_SEPARATOR; i++);
        char *temp = parse_word(start, i - 1, buff->file_content);
        r_add_word(temp, buff);
        start = i;
        free(temp);
    }
    buff->rep[0] = i + 2;
    return (buff);
}
