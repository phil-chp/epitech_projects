/*
** EPITECH PROJECT, 2021
** antman
** File description:
** Free's everything used by antman
*/

#include <stdlib.h>
#include "../include/assets.h"

void free_content(buff_t *buff, char *file_str)
{
    for (int i = 0; buff->array[i]; i++)
        if (buff->array[i]) free(buff->array[i]);
    if (buff->file_content) free(buff->file_content);
    if (buff->array) free(buff->array);
    if (buff->rep) free(buff->rep);
    if (file_str) free(file_str);
    if (buff) free(buff);
}
