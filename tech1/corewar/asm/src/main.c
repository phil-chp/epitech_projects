/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include "asm.h"

int compare_word(char *str)
{
    short i = 0;

    for (; str[i] != ','; i++);
    return (i);
}

char instruct_forest(char *str)
{
    short i = 0;

    for (; op_tab[i].mnemonique; i++)
        if (my_strcmp(str, op_tab[i].mnemonique) == 0)
            return (i + 1);
    return ERROR_VERIF;
}

int get_asm(asmb_t *asmm, header_t *header, char *path)
{
    number_u magic;
    // number_u tmp;
    int size;

    magic.char1 = 'V';
    magic.char2 = 'A';
    magic.char3 = 'P';
    magic.char4 = 'Q';
    header->magic = magic.nb;
    if (get_name(asmm, header)) return ERROR_VERIF;
    if (get_comment(asmm, header)) return ERROR_VERIF;
    if ((size = get_command(asmm)) < 0) return ERROR_VERIF;
    header->prog_size = size;
    // magic.char4 = tmp.char1;
    // magic.char3 = tmp.char2;
    // magic.char2 = tmp.char3;
    // magic.char1 = tmp.char4;
    // header->prog_size = size;
    header->prog_size = my_swap_endian(header->prog_size);
    if (asm_to_cor(asmm, header, size, path)) return ERROR_VERIF;
    return 0;
}

int manage_asmm(char *path)
{
    asmb_t asmm;
    header_t header;

    if (!(my_strcmp(path, "-h"))) {
        print_usage();
        return 0;
    }
    if (read_and_check(&asmm, path)) return ERROR_VERIF;
    if (get_asm(&asmm, &header, path)) return ERROR_VERIF;
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2) return ERROR;
    if (manage_asmm(av[1])) return ERROR;
    return (0);
}
