/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** elf
*/

#include "utils.h"

architecture_t check_elf(void *file_contents)
{
    Elf32_Ehdr *header;
    my_elf_t *elf;

    header = (Elf32_Ehdr *)file_contents;
    elf = (void *)header->e_ident;
    if (header->e_type != ET_DYN  \
    &&  header->e_type != ET_REL  \
    &&  header->e_type != ET_EXEC) {
        ERROR("my_nm: invalid file\n");
        return (ARCH_UNKNOWN);
    }
    if (CHECK_MAGIC(elf->magic) && elf->arch != ARCH_UNKNOWN
    && elf->endian != ENDIAN_ERROR && elf->version != VERSION_ERROR) {
        return (elf->arch);
    }
    ERROR("my_nm: file format not recognized\n");
    return (ARCH_UNKNOWN);
}
