/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** solver lib
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stddef.h>
#include <stdbool.h>
#include "my.h"

#define WALL  (const char)'X'
#define PATH  (const char)'*'
#define PASS  (const char)'o'

typedef struct cell_s {
    int x;
    int y;
} cell_t;

typedef struct solver_s {
    int x;
    int y;
    char **map;
} sol_t;

typedef struct node_s {
    struct node_s *parent;
    bool visited;
    cell_t pos;
} node_t;

typedef struct list_s {
    node_t node;
    struct list_s *next, *head;
} list_t;

// - - - - -  MAZE  - - - - //
void backtrack(sol_t *sol, node_t *node);
void solve_maze(sol_t *sol, cell_t start, cell_t end);

// - - - - - UTILS  - - - - //
char *read_file(char *file);
int error_handling(int return_code);
void destroy_map(sol_t *sol);

#endif /* SOLVER_H_ */
