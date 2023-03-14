/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdbool.h>
#include <stddef.h>
#include "my.h"

#define WALL  (const char)'X'
#define PATH  (const char)'*'

typedef struct cell_s {
    int x;
    int y;
} cell_t;

typedef struct generator_s {
    int x;
    int y;
    bool perfect;
    char **map;
} gen_t;

// - - - - - MAZE  - - - - //
int create_empty_maze(gen_t *gen);
int get_neighbors(gen_t *gen, cell_t *cell);
int generate_maze(gen_t *gen);

// - - - -  UTILS  - - - - //
int error_handling(int return_code);
void destroy_map(gen_t *gen);

#endif /* GENERATOR_H_ */
