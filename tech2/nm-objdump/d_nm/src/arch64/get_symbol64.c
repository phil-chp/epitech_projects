/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** get_symbol
*/

#include "nm.h"

static char get_symbol_info(char c, Elf64_Sym symtab)
{
    if (c != '?') return (c);
    if (ELF64_ST_BIND(symtab.st_info) == STB_GNU_UNIQUE) {
        c = 'u';
    } else if (ELF64_ST_BIND(symtab.st_info) == STB_WEAK) {
        c = (symtab.st_shndx == SHN_UNDEF ? 'w' : 'W');
    } else {
        if (ELF64_ST_BIND(symtab.st_info) == STB_WEAK  \
        &&  ELF64_ST_TYPE(symtab.st_info) == STT_OBJECT) {
            c = (symtab.st_shndx == SHN_UNDEF ? 'v' : 'V');
        }
    }
    return (c);
}

static char get_symbol_section(char c, Elf64_Sym symtab)
{
    if (c != '?') return (c);
    if (symtab.st_shndx == SHN_UNDEF) {
        c = 'U';
    } else if (symtab.st_shndx == SHN_ABS) {
        c = 'A';
    } else if (symtab.st_shndx == SHN_COMMON) {
        c = 'C';
    }
    return (c);
}

static char get_symbol_shared_type(char c, Elf64_Sym symtab, Elf64_Shdr *shared)
{
    if (c != '?') return (c);
    if (shared[symtab.st_shndx].sh_type  == SHT_NOBITS \
    &&  shared[symtab.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) {
        c = 'B';
    } else if (shared[symtab.st_shndx].sh_type  == SHT_PROGBITS \
    &&         shared[symtab.st_shndx].sh_flags == SHF_ALLOC) {
        c = 'R';
    } else {
        uint64_t alloc_or_execinstr = (SHF_ALLOC | SHF_EXECINSTR);
        if ((shared[symtab.st_shndx].sh_type  == SHT_PROGBITS \
        &&   shared[symtab.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        ||   shared[symtab.st_shndx].sh_type  == SHT_DYNAMIC) {
            c = 'D';
        } else if (shared[symtab.st_shndx].sh_type  == SHT_PROGBITS
        &&         shared[symtab.st_shndx].sh_flags == alloc_or_execinstr) {
            c = 'T';
        }
    }
    return (c);
}

static char get_symbol_program_header(char c, Elf64_Sym symtab, \
                                        Elf64_Phdr *program)
{
    if (c != '?') return (c);
    if (program[symtab.st_shndx].p_flags == PF_R) {
        c = 'R';
    } else if (program[symtab.st_shndx].p_type == PT_LOAD
    ||         program[symtab.st_shndx].p_type == PT_PHDR) {
        c = 'D';
    }
    return (c);
}

char get_symbol64(Elf64_Sym symtab, Elf64_Shdr *shared, Elf64_Phdr *program)
{
    char c = '?';

    c = get_symbol_info(c, symtab);
    c = get_symbol_section(c, symtab);
    c = get_symbol_shared_type(c, symtab, shared);
    c = get_symbol_program_header(c, symtab, program);
    if (c != '?' && ELF64_ST_BIND(symtab.st_info) == STB_LOCAL)
        c += 32;
    return (c);
}
