/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** init64
*/

#include "objdump.h"

void get_elf64(elf64_t *obj, void *file_contents)
{
    obj->header = (Elf64_Ehdr *)(file_contents);
    obj->shared = (Elf64_Shdr *)((size_t)file_contents + obj->header->e_shoff);
}
