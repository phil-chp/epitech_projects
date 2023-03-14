/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_

# include <stdbool.h>
# include "utils.h"

# define MAX_ITERATION 9999

/*  64  */
bool init_elf64(elf64_t *obj, void *dump);
void get_elf64(elf64_t *obj, void *file_contents);
void print_header64(elf64_t *obj, size_t i);

/*  32  */
bool init_elf32(elf32_t *obj, void *dump);
void get_elf32(elf32_t *obj, void *file_contents);
void print_header32(elf32_t *obj, size_t i);

#endif /* !OBJDUMP_H_ */
