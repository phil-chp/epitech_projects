/*
** EPITECH PROJECT, 2022
** ftrace (Workspace)
** File description:
** delf
*/

#include <libelf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include "delf.h"

Elf *delf_start(char *file)
{
    Elf *elf = NULL;
    int fd = 0;

    elf_version(EV_CURRENT);
    fd = open(file, O_RDONLY);
    if (!fd) {
        fprintf(stderr, "start_elf: cannot open file");
        return (NULL);
    }
    elf = elf_begin(fd, ELF_C_READ, NULL);
    if (elf == NULL) {
        fprintf(stderr, "start_elf: file format not recognized as ELF");
    }
    return (elf);
}

void delf_end(Elf *elf)
{
    if (elf) elf_end(elf);

}

void init_delf64(Elf *elf, delf64_t *delf)
{
    (void)elf;
    delf->scn = NULL;
    delf->data = NULL;
    delf->shdr = NULL;
    delf->sym = NULL;
}

char *delf_get_symbol(Elf *elf, long address)
{
    // TODO: move to structure :)
    delf64_t delf = {NULL, NULL, NULL, NULL};

    // init_delf64(elf, &delf);//pas besoin ?
    while ((delf.scn = elf_nextscn(elf, delf.scn)) != NULL) {
        delf.shdr = elf64_getshdr(delf.scn);
        if (delf.shdr->sh_type != SHT_SYMTAB) continue;
        delf.data = elf_getdata(delf.scn, NULL);
        delf.sym = (Elf64_Sym *)delf.data->d_buf;

        for (size_t i = 0; i < delf.shdr->sh_size / delf.shdr->sh_entsize; i++) {
            // if (ELF64_ST_TYPE(sym[i].st_info) != STT_FUNC) continue;
            // printf("value: %lx\taddr: %lx\tstr: %s\n", delf.sym[i].st_value, address, elf_strptr(elf, delf.shdr->sh_link, delf.sym[i].st_name));
            if ((long signed)delf.sym[i].st_value != address) continue;
            return (elf_strptr(elf, delf.shdr->sh_link, delf.sym[i].st_name));
        }
    }
    // puts("\n");
    return (NULL);
}
