/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** utils
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <unistd.h>
# include <string.h>
# include <elf.h>
# include <sys/mman.h>

# define BITS64 64
# define BITS32 32

# define ELF_MAGIC_LSB 0x7f454c46
# define ELF_MAGIC_MSB 0x464c457f

# define ENDIAN_ERROR 0
# define VERSION_ERROR 0

# define CHECK_MAGIC(magic) (magic == ELF_MAGIC_LSB || magic == ELF_MAGIC_MSB)

/* Print error message */
# define ERROR(message) write(2, message, strlen(message));

typedef enum architecture_e {
    ARCH_UNKNOWN,
    ARCH_32BITS,
    ARCH_64BITS
} architecture_t;

typedef struct my_elf_s {
    int magic;
    unsigned char arch;
    unsigned char endian;
    unsigned char version;
    unsigned char os;
    unsigned char abi_version;
} my_elf_t;

// - - - - - - 32 BIT - - - - - - //

typedef struct data32_s {
    uint32_t value;
    char     symbol;
    char    *name;
} data32_t;

typedef struct elf32_s {
    Elf32_Ehdr *header;
    Elf32_Shdr *shared;
    Elf32_Phdr *program;
    Elf32_Sym  *symtab;
    Elf32_Shdr *strtab;
    size_t      data_size;
    data32_t   *data;
} elf32_t;

// - - - - - - 64 BIT - - - - - - //

typedef struct data64_s {
    uint64_t value;
    char     symbol;
    char    *name;
} data64_t;

typedef struct elf64_s {
    Elf64_Ehdr *header;
    Elf64_Shdr *shared;
    Elf64_Phdr *program;
    Elf64_Sym  *symtab;
    Elf64_Shdr *strtab;
    size_t      data_size;
    data64_t   *data;
} elf64_t;

/*  ELF  */
architecture_t check_elf(void *file_contents);

/* File handling */
void *get_map_file(char *file);
void unmap_file(void *file_contents);

/* General parsing */
char *my_strlowcase(char *str);
int isalphanum(char const c);

#endif /* !UTILS_H_ */
