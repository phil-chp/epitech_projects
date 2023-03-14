/*
** EPITECH PROJECT, 2020
** get_command.c
** File description:
** get command
*/

#include "asm.h"

char get_bin(char **args, int nb, int index)
{
    binary_u tmp;
    int add = 0;

    tmp.c = 0;
    if (my_tablen(args) != nb) return -1;
    if (index == 0 || index == 11 || index == 8 || index == 14)
        return (0);
    for (register short i = 0; i < nb; i++, tmp.c <<= 2) {
        add = (args[i][0] == 'r' ? 1 : (args[i][0] == '%' ? 2 : \
        (args[i][0] >= '0' && args[i][0] <= '9' ? 3 : 0)));
        if (add == 0) return 1;
        tmp.c += add;
    }
    tmp.c <<= ((3 - nb) * 2);
    return tmp.c;
}

int get_arg(char **command, int temp, int *size, char *arg)
{
    number_u tmp;

    tmp.nb = 0;
    *size += temp;
    *command = realloc(*command, *size);
    if (!*command) return (ERROR_MEM);
    if (arg[0] == 'r' || arg[0] == '%') {
        tmp.nb = my_getnbr(&arg[1]);
        if (arg[0] == 'r' && tmp.nb > 16) return (ERROR_VERIF);
    }
    else if (arg[0] >= '0' && arg[0] <= '9')
        tmp.nb = my_getnbr(arg);
    else
        return (ERROR_VERIF);
    for (register short i = 0; i < temp; i++, tmp.nb >>= 8)
        (*command)[*size - i -1] = tmp.char1;
    return (0);
}

int get_args_size(char **command, char **word, int *size)
{
    binary_u bincut;
    unsigned char bin = (*command)[*size - 1];
    short n = (*command)[*size - 2] - 1;
    short nb = op_tab[n].nbr_args;
    short tm = 0, size_total = 0;

    if (my_tablen(word) != nb) return -1;
    bincut.c = bin;
    for (register short i = 0; i < nb; i++, bincut.c <<= 2) {
        if (bincut.duo4 == 1) tm = 1;
        if (bincut.duo4 == 2)
            tm = (n == 1 || (n > 4 && n < 8) || n == 12 ? 4 : 2);
        if (bincut.duo4 == 3) tm = 2;
        if (bincut.duo4 == 0)
            tm = (n == 0 ? 3 : 1);
        if (get_arg(command, tm, size, word[i])) return ERROR_VERIF;
    }
    size_total = *size;
    return (size_total);
}

int get_opt(char **com, char **words, int *size)
{
    short grow = 0, size_total = 0;

    *size += 2;
    if (my_tablen(words) < 2) return (-1);
    (*com) = realloc((*com), *size);
    if (!(*com)) return ERROR_MEM;
    if (((*com)[*size - 2] = instruct_forest(words[0])) == -1) return -1;
    grow = op_tab[(int)(*com)[*size - 2] - 1].nbr_args;
    if (((*com)[*size - 1] = get_bin(
        &words[1], grow, (*com)[*size - 2] - 1)) == 1) return -1;
    if ((size_total = get_args_size(com, &words[1], size)) < 0) return -1;
    return size_total;
}

int get_command(asmb_t *asmm)
{
    int size = 0;
    short check = 0, size_total = 0;
    short i = 2;
    char **tmp;

    asmm->command = NULL;
    for (; asmm->tab[i] && check == 0; i++) {
        tmp = my_str_to_word_array(asmm->tab[i], "\t, ");
        if (asmm->tab[i]) free(asmm->tab[i]);
        if (!tmp) return ERROR_VERIF;
        if ((size_total \
        = get_opt(&asmm->command, tmp, &size)) < 0) return ERROR_VERIF;
    }
    if (asmm->tab) free (asmm->tab);
    return size_total;
}
