/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** create_maze
*/

#include <stdlib.h>
#include "generator.h"

static int handle_y_spe_case(gen_t *gen)
{
    char *mem;

    if (!(mem = my_strdup_char(PATH, gen->x)))
        return (1);
    if (!(gen->map[0] = my_strdup(mem)))
        return (1);
    if (mem) free(mem);
    return (1);
}

int create_empty_maze(gen_t *gen)
{
    char *temp;
    int i = 0;

    if (!(temp = my_strdup_char(WALL, gen->x)))
        return (1);
    gen->map = malloc(sizeof(char *) * (gen->y + 1));
    if (!gen->map)
        return (1);
    if (!(gen->x % 2)) temp[0] = PATH;
    if (!(gen->y % 2)) i = handle_y_spe_case(gen);
    for (; i < gen->y; i++) {
        if (!(gen->map[i] = my_strdup(temp)))
            return (1);
    }
    gen->map[i] = NULL;
    gen->map[0][0] = PATH;
    if (temp) free(temp);
    return (0);
}
