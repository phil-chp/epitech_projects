/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** header64
*/

#include <stdio.h>
#include "objdump.h"

void print_header64(elf64_t *obj, size_t i)
{
    printf("%5cfile format elf64-x86-64\n", ' ');
    printf("architecture: i386:x86-64, flags 0x%08x:\n",    \
                    obj->header[i].e_flags);
    printf("HAS_SYMS, DYNAMIC, D_PAGED\n");
    printf("start address 0x%016lx\n", obj->header[i].e_entry);
    printf("\n");
}
