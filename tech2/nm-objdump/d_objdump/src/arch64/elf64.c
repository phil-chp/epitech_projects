/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** elf64
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h> // TODO: REMOVE
#include "objdump.h"

static size_t get_size_in_blocks(size_t size)
{
    for (size_t blocks = 1; blocks < MAX_ITERATION; ++blocks) {
        if (size <= blocks * 16) {
            return (blocks);
        }
    }
    return (0);
}

static void print_hex(void *dump, size_t position, size_t size, size_t i)
{
    size_t j = 0;

    for (; j < 16 && (i * 16) + j < size; ++j) {
        char value = ((char *)dump)[position + (i * 16) + j];
        if (j % 4 == 0) printf(" ");
        printf("%02hhx", value);
    }
    for (; j < 16; ++j) {
        if (j % 4 == 0) {
            printf(" ");
        }
        printf("  ");
    }
}

static void print_ascii(void *dump, size_t position, size_t size, size_t i)
{
    size_t j = 0;

    for (; j < 16 && (i * 16) + j < size; ++j) {
        char value = ((char *)dump)[position + (i * 16) + j];
        if (value < 32 || value > 126) value = '.';
        printf("%c", value);

    }
    for (; j < 16; ++j) {
        printf(" ");
    }
}

static void print_data64(elf64_t *obj, Elf64_Shdr section,      \
                            char *tbl, void *dump)
{
    size_t position, size, blocks, index_len;
    char max_index[64];

    position = section.sh_addr;
    size = section.sh_size;
    blocks = get_size_in_blocks(size);
    sprintf(max_index, "%lx", (position + (blocks - 1) * 16));
    index_len = (strlen(max_index) > 4 ? strlen(max_index) : 4);
    printf("Contents of section %s:\n", &tbl[section.sh_name]);
    for (size_t i = 0; i < blocks; ++i) {
        if (i > size) return;
        printf(" %0*lx", (int)index_len, position + (i * 16));
        print_hex(dump, position, size, i);
        printf("  ");
        print_ascii(dump, position, size, i);
        printf("\n");
    }
}

bool init_elf64(elf64_t *obj, void *dump)
{
    bool header_printed = false;
    char *tbl;

    get_elf64(obj, dump);
    tbl = (char *)(dump + obj->shared[obj->header->e_shstrndx].sh_offset);
    for (size_t i = 0; i < obj->header->e_shnum; ++i) {
        if (obj->shared[i].sh_size == 0) continue;
        if (strcmp(&tbl[obj->shared[i].sh_name], ".bss")      == 0  \
        ||  strcmp(&tbl[obj->shared[i].sh_name], ".symtab")   == 0  \
        ||  strcmp(&tbl[obj->shared[i].sh_name], ".strtab")   == 0  \
        ||  strcmp(&tbl[obj->shared[i].sh_name], ".shstrtab") == 0) {
            continue;
        }
        if (header_printed == false) {
            header_printed = true;
            print_header64(obj, i);
        }
        print_data64(obj, obj->shared[i], tbl, dump);
    }
    return (0);
}
