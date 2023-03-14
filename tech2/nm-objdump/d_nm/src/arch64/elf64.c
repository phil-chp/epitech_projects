/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** elf64
*/

#include <stdlib.h>
#include <string.h>
#include "nm.h"

static void init_nm(elf64_t *nm, void *file_contents)
{
    nm->header  = (Elf64_Ehdr *)(file_contents);
    nm->shared  = (Elf64_Shdr *)((size_t)file_contents + nm->header->e_shoff);
    nm->program = (Elf64_Phdr *)((size_t)file_contents + nm->header->e_phoff);
}

bool init_elf64(elf64_t *nm, void *dump)
{
    size_t symtab_index = 0;
    char *tbl;

    init_nm(nm, dump);
    tbl = (char *)(dump + nm->shared[nm->header->e_shstrndx].sh_offset);
    for (size_t i = 0; i < nm->header->e_shnum; ++i)
        if (strcmp(&tbl[nm->shared[i].sh_name], ".symtab") == 0) {
            nm->symtab = (Elf64_Sym *)(dump + nm->shared[i].sh_offset);
            symtab_index = i;
        } else if (strcmp(&tbl[nm->shared[i].sh_name], ".strtab") == 0) {
            nm->strtab = (Elf64_Shdr *)&nm->shared[i];
        }
    if (symtab_index == 0) {
        ERROR("my_nm: no symbols\n");
        return (1);
    }
    void *name_offset = (void *)((size_t)dump + nm->strtab->sh_offset);
    build_data64(nm, &nm->data, symtab_index, name_offset);
    sort_data64(nm);
    return (0);
}
