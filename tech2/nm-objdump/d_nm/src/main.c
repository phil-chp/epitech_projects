/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** main
*/

#include <stdio.h>
# include <stdbool.h>
#include "nm.h"

static int call_correct_architecture(void *file_contents)
{
    architecture_t architecture;

    architecture = check_elf(file_contents);
    if (architecture == ARCH_64BITS) {
        elf64_t elf64;
        if (init_elf64(&elf64, file_contents) == 1) return (1);
        print_data64(&elf64);
    } else if (architecture == ARCH_32BITS) {
        elf32_t elf32;
        if (init_elf32(&elf32, file_contents) == 1) return (1);
        print_data32(&elf32);
    } else {
        return (1);
    }
    return (0);
}

static int my_nm(char *file)
{
    void *file_contents;

    file_contents = get_map_file(file);
    if (file_contents == NULL) {
        ERROR("my_nm: file not found\n");
        return (1);
    }
    if (call_correct_architecture(file_contents) == 1) return (1);
    unmap_file(file_contents);
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2) {
        ERROR("my_nm: Bad arguments.\n");
        return (84);
    } else if (ac >= 2 && av[1][0] == '-' &&  av[1][1] == 'h') {
        write(1, "\nUSAGE\n\t./my_nm <file>\n", 23);
        return (0);
    }
    if (ac == 2) {
        if (my_nm(av[1]) == 1) return (84);
        return (0);
    }
    for (int i = 1; i < ac; i++) {
        printf("\n%s:\n", av[i]);
        if (my_nm(av[i]) == 1) return (84);
    }
    return (0);
}
