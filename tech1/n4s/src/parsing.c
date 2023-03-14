/*
** EPITECH PROJECT, 2021
** n4s
** File description:
** parsing
*/

#include <stdlib.h>
#include "ai.h"
#include "my.h"

bool cp_parser(info_t *info, char ***tab, size_t pos)
{
    char cp = 0;

    if ((*tab)[pos + 2] && (*tab)[pos + 3]) {
        cp = (*tab)[pos + 3][0];
        info->cp.info                               \
        = (cp == 'N' ? NOTHING                      \
        : (cp == 'F' ? FIRST_CP_CLEARED             \
        : (cp == 'C' ? CP_CLEARED                   \
        : (cp == 'L' ? LAP_CLEARED : TRACK_CLEARED))));
    }
    return (0);
}

bool values_parser(info_t *info, char ***tab, size_t pos)
{
    if (pos > 0) {
        if (info->values) free(info->values);
        if (!(info->values = malloc(sizeof(int) * pos))) // free at end
            return (1);
        for (size_t i = 0, j = 3; (*tab)[j] && j < pos + 3; i++, j++)
            if ((info->values[i] = my_getnbr((*tab)[j])) < 0) return (1);
    }
    return (0);
}

bool main_parser(info_t *info, char **output, char *delim)
{
    char **tab = NULL;

    info->type_cp = false;
    info->id_status = false;
    tab = my_str_to_word_array_div(*output, *delim);
    if ((info->id = my_getnbr(tab[0])) < 0)
        return (1);
    info->status = (tab[1][0] == 'O' ? 1 : 0);
    info->type = 32;
    info->id_status = true;
    if (tab[3][0] == 'N') return (0);
    info->type_cp = false;
    if (values_parser(info, &tab, info->type))
        return (1);
    if (cp_parser(info, &tab, info->type))
        return (1);
    info->type_cp = true;
    free_tab(&tab);
    return (0);
}
