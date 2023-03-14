/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** print32
*/

#include <stdio.h>
#include "nm.h"

void print_data32(elf32_t *nm)
{
    for (size_t i = 0; i < nm->data_size; i++) {
        printf("%016x %c %s\n", nm->data[i].value,  \
                nm->data[i].symbol, nm->data[i].name);
    }
}
