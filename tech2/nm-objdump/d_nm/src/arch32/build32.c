/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** build
*/

#include <stdlib.h>
#include "nm.h"

static char *init_name(elf32_t *nm, data32_t *data, size_t i, void *name_offset)
{
    size_t name_size;

    name_size = strlen((char *)((size_t)name_offset + nm->symtab[i].st_name));
    data->name = (char *)malloc(sizeof(char) * (name_size + 1));
    return ((char *)((size_t)name_offset + nm->symtab[i].st_name));
}

void build_data32(elf32_t *nm, data32_t **data,    \
                size_t symtab_index, void *name_offset)
{
    size_t n = 0, j = 0;

    nm->data_size = nm->shared[symtab_index].sh_size / sizeof(Elf32_Sym);
    for (size_t i = 0; i < nm->data_size; ++i) {
        if (strlen((char *)&nm->symtab[i].st_name) == 0
        ||  get_symbol32(nm->symtab[i], nm->shared, nm->program) == 'a') ++n;
    }
    (*data) = malloc(sizeof(data32_t) * (nm->data_size - n));
    for (size_t i = 0; i < nm->data_size; ++i) {
        if (strlen((char *)&nm->symtab[i].st_name) == 0
        ||  get_symbol32(nm->symtab[i], nm->shared, nm->program) == 'a') {
            continue;
        }
        (*data)[j].symbol = \
            get_symbol32(nm->symtab[i], nm->shared, nm->program);
        (*data)[j].value  = nm->symtab[i].st_value;
        (*data)[j].name = init_name(nm, &(*data)[j], i, name_offset);
        ++j;
    }
    nm->data_size -= n;
}
