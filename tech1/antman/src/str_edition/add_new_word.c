/*
** EPITECH PROJECT, 2021
** antman
** File description:
** add new element with iteration 0
*/

#include <stdlib.h>
#include <stdlib.h>
#include "../../include/assets.h"
#include "../../include/my.h"

void add_new_word(char *temp, buff_t *buff)
{
    int i = 0;
    if (buff->check == 1) {
        buff->array[0] = my_strdup(temp);
        buff->array[1] = NULL;
        buff->rep[0] = 1;
        buff->rep[1] = 0;
        buff->check = 0;
    }
    for (; buff->array[i]; i++);
    buff->array[i] = my_strdup(temp);
    buff->array[i + 1] = NULL;
    buff->rep[i] = 1;
    buff->rep[i + 1] = 0;
}
