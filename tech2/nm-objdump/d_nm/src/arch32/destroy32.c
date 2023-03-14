/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** destroy32
*/

#include <stdlib.h>
#include "nm.h"

void destroy_elf32(elf32_t *nm)
{
    for (size_t i = 0; i < nm->data_size - 1; ++i) {
        if (nm->data[0].name)
            free(nm->data[0].name);
    }
}
