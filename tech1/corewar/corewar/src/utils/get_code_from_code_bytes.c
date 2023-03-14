/*
** EPITECH PROJECT, 2020
** B-CPE-201-NCE-2-1-corewar-philippe.cheype
** File description:
** manager.c
*/

#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "corewar.h"
#include "shared.h"
#include "my.h"

static __u_int *code_bytes_to_args( char sizes[4],       \
                                    __u_char **arena,    \
                                    __u_int *pos)
{
    ssize_t j, n, save;
    unsigned int *params;
    size_t temp = 0;
    number_u arg;

    if (!(params = malloc(sizeof(unsigned int *) * 4))) return (NULL);
    for (j = 0; sizes[j] != 0 && j < 4; j++) {
        arg.nb = 0;
        for ((*pos), n = 0; n < sizes[j]; (*pos)++, n++) {
            if ((*pos) > 4095) (*pos) = 0;
            arg.c[sizes[j] - n - 1] = (*arena)[(*pos)];
        }

        params[j] = arg.nb;
    }
    params[j] = 0;
    return (params);
}

static bool args_parsing(   __u_char **arena,       \
                            code_t *code,           \
                            char (*sizes)[4],       \
                            __u_int *pos)
{
    ssize_t j = 0;
    bin_u nb;

    if (!(nb.c = (*arena)[(*pos)++])) return (1);
    if (nb.d1 != 0) return (1);
    for (; j < 3; j++, nb.c <<= 2) {
        if (nb.d4 == 0) break;
        (*sizes)[j] = ((code->f == 2 || (code->f > 5 && code->f < 9)    \
        || code->f == 13) && nb.d4 == 2 ? 4 : (nb.d4 == 1 ? 1 : 2));
        code->types[j] = (nb.d4 == 2 ? T_IND : (nb.d4 == 1 ? T_REG : T_DIR));
    }
    (*sizes)[j] = '\0';
    code->types[j] = '\0';
    if (nb.c) return (1);
    return (0);
}

static bool get_args_from_special_cases(char (*sizes)[4],        \
                                        args_type_t (*type)[4],  \
                                        char func_name)
{
    for (size_t i = 0; i < 4; i++) {
        (*sizes)[i] = 0;
        (*type)[i] = 0;
    }
    (*sizes)[0] = (func_name == 1 ? 4 : 2);
    return (0);
}

__u_int get_code_from_code_bytes(   __u_char **arena,
                                    code_t *code,
                                    __u_int pos)
{
    char sizes[4];
    __u_int temp;

    code->f = (*arena)[pos++];
    if (code->f == 0 || code->f > 16) return (pos);
    if (code->f == 1 || code->f == 9 || code->f == 12 || code->f == 15) {
        get_args_from_special_cases(&sizes, &code->types, code->f);
    } else {
        if (args_parsing(arena, code, &sizes, &pos)) {
            return (pos);
        }
    }
    temp = pos;
    if (code->params) free(code->params);
    if (!(code->params = code_bytes_to_args(sizes, arena, &pos))) {
        return (temp);
    }
    return (pos);
}
