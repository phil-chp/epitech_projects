/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** sort
*/

#include <stdlib.h>
#include "nm.h"

static void sanitize_str(char **str)
{
    size_t i = 0;
    for (; (*str)[i] != '\0' && isalphanum((*str)[i]); ++i);
    if (i > 0) {
        memmove(*str, *str + i, strlen(*str) - i + 1);
    }
    *str = my_strlowcase(*str);
}

static void swap_data(data64_t *data, size_t i, size_t j)
{
    data64_t tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

void sort_data64(elf64_t *nm)
{
    for (size_t i = 0; i < nm->data_size - 1; ++i) {
        for (size_t j = 0; j < nm->data_size - i - 1; ++j) {
            char *first = strdup(nm->data[j].name);
            char *second = strdup(nm->data[j + 1].name);
            sanitize_str(&first);
            sanitize_str(&second);
            if (strcmp(first, second) > 0) swap_data(nm->data, j, j + 1);
            if (first) free(first);
            if (second) free(second);
        }
    }
}
