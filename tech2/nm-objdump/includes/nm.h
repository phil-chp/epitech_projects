/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** nm
*/

#ifndef NM_H_
# define NM_H_

# include <stdbool.h>
# include "utils.h"

/*  64  */
bool init_elf64(elf64_t *nm, void *file_contents);
void print_elf64(elf64_t *elf64);
void destroy_elf64(elf64_t *nm);

char get_symbol64(Elf64_Sym symtab, Elf64_Shdr *shared, Elf64_Phdr *program);
void sort_data64(elf64_t *nm);
void build_data64(elf64_t *nm, data64_t **data, \
                size_t symtab_index, void *name_offset);
void print_data64(elf64_t *nm);

/*  32  */
bool init_elf32(elf32_t *nm, void *file_contents);
void print_elf32(elf32_t *elf32);
void destroy_elf32(elf32_t *nm);

char get_symbol32(Elf32_Sym symtab, Elf32_Shdr *shared, Elf32_Phdr *program);
void sort_data32(elf32_t *nm);
void build_data32(elf32_t *nm, data32_t **data, \
                size_t symtab_index, void *name_offset);
void print_data32(elf32_t *nm);

#endif /* !NM_H_ */
