/*
** EPITECH PROJECT, 2022
** ftrace (Workspace)
** File description:
** delf
*/

#ifndef DELF_H_
    #define DELF_H_

    #include <libelf.h>


typedef struct delf64_s {
    Elf_Scn *scn;
    Elf_Data *data;
    Elf64_Shdr *shdr;
    Elf64_Sym *sym;
} delf64_t;

// _______________________ ELF _______________________ //

/**
 * @brief Return descriptor for ELF file to work according to CMD.
 *
 * @param file The file to read
 * @return [ Elf* ] The ELF descriptor
 */
Elf *delf_start(char *file);

/**
 * @brief Free resources allocated for ELF.
 *
 * @param elf The ELF descriptor
 */
void delf_end(Elf *elf);

/**
 * @brief Prints the ELF header
 *
 * @param file The file to read
 * @param address The address of the ELF header in hexa ie: "0x1080"
 * @return [ char* ] The ELF header symbol
 */
char *delf_get_symbol(Elf *elf, long address);

#endif /* !DELF_H_ */
