/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** generate_map
*/

#include "generator.h"

int generate_maze(gen_t *gen)
{
    int sx = 0;
    int sy = 0;

    if (gen->map[0][1] == PATH) sy++;
    if (gen->map[1][0] == PATH) sx++;
    for (int x = sx; x < gen->x; x += 2) {
        for (int y = sy; y < gen->y; y += 2) {
            cell_t cell = { x, y };
            if (get_neighbors(gen, &cell) == 0) continue;
            gen->map[y][x] = PATH;
            gen->map[cell.y][cell.x] = PATH;
        }
    }
    if (gen->perfect == false) {
        for (int n = 0; n < gen->y; n++)
            gen->map[n][gen->x * 3 / 4] = PATH;
        for (int n = 0; n < gen->x; n++)
            gen->map[gen->y * 3 / 4 - 1][n] = PATH;
    }
    return (0);
}
