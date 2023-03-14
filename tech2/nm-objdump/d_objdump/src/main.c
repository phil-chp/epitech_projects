/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** main
*/

#include <stdio.h>
#include "objdump.h"

static int call_correct_architecture(void *file_contents)
{
    architecture_t architecture;

    architecture = check_elf(file_contents);
    if (architecture == ARCH_64BITS) {
        elf64_t elf64;
        if (init_elf64(&elf64, file_contents) == 1) return (1);
    } else {
        ERROR("my_objdump: file format not recognized\n");
        return (1);
    }
    return (0);
}

static int my_objdump(char *file)
{
    void *file_contents;

    file_contents = get_map_file(file);
    if (file_contents == NULL) {
        ERROR("my_objdump: file not found\n");
        return (1);
    }
    if (call_correct_architecture(file_contents) == 1) return (1);
    unmap_file(file_contents);
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2) {
        ERROR("objdump: Bad arguments.\n");
        return (84);
    } else if (ac >= 2 && av[1][0] == '-' &&  av[1][1] == 'h') {
        write(1, "\nUSAGE\n\t./my_objdump <file>\n", 28);
        return (0);
    }
    for (int i = 1; i < ac; i++) {
        printf("\n%s:", av[i]);
        if (my_objdump(av[i]) == 1) return (84);
    }
    return (0);
}
