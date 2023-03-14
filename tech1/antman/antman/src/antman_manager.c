/*
** EPITECH PROJECT, 2021
** antman
** File description:
** Handles the entire antman project
*/

#include <stdlib.h>
#include "../../include/assets.h"
#include "../../include/my.h"

buff_t *antman_manager(char *file_str)
{
    buff_t *buff;
    int i = 0;
    int start = i;

    buff = init_buff(file_str, A_STEP);
    if (!buff) return (NULL);
    for (; file_str[i]; i++) {
        for (; IS_NOT_SEPARATOR && FILE_EXISTS; i++);
        for (; IS_SEPARATOR; i++);
        char *temp = parse_word(start, i - 1, file_str);
        check_word(temp, buff);
        start = i;
        free(temp);
    }
    return (buff);
}
