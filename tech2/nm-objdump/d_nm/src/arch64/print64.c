/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** print64
*/

#include <stdio.h>
#include "nm.h"

void print_data64(elf64_t *nm)
{
    for (size_t i = 0; i < nm->data_size; i++) {
        printf("%016lx %c %s\n", nm->data[i].value, \
            nm->data[i].symbol, nm->data[i].name);
    }
}
