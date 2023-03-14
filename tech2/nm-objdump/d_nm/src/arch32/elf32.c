/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** elf32
*/

#include <stdlib.h>
#include <string.h>
#include "nm.h"

static void init_nm(elf32_t *nm, void *file_contents)
{
    nm->header  = (Elf32_Ehdr *)(file_contents);
    nm->shared  = (Elf32_Shdr *)((size_t)file_contents + nm->header->e_shoff);
    nm->program = (Elf32_Phdr *)((size_t)file_contents + nm->header->e_phoff);
}

bool init_elf32(elf32_t *nm, void *dump)
{
    size_t symtab_index = 0;
    char *n;

    init_nm(nm, dump);
    n = (char *)((size_t)dump + nm->shared[nm->header->e_shstrndx].sh_offset);
    for (size_t i = 0; i < nm->header->e_shnum; ++i)
        if (strcmp(&n[nm->shared[i].sh_name], ".symtab") == 0) {
            nm->symtab = (Elf32_Sym *)(dump + nm->shared[i].sh_offset);
            symtab_index = i;
        } else if (strcmp(&n[nm->shared[i].sh_name], ".strtab") == 0) {
            nm->strtab = (Elf32_Shdr *)&nm->shared[i];
        }
    if (symtab_index == 0) {
        ERROR("my_nm: no symbols\n");
        return (1);
    }
    void *name_offset = (void *)((size_t)dump + nm->strtab->sh_offset);
    build_data32(nm, &nm->data, symtab_index, name_offset);
    sort_data32(nm);
    return (0);
}
