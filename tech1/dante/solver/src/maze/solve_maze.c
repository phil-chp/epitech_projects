/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** solve_maze
*/

#include <stdlib.h>
#include "solver.h"
#include "stack.h"
#include <stdio.h>  // TO REM
static void init_node(node_t *start_node, node_t *end_node, cell_t *start, cell_t *end)
{
    start_node->visited = true;
    end_node->visited   = false;
    start_node->parent  = NULL;
    end_node->parent    = NULL;
    start_node->pos     = (*start);
    end_node->pos       = (*end);
}

static int check_if_goal_reached(node_t *current_node, cell_t *end)
{
    return (current_node->pos.x == end->x && current_node->pos.y == end->y);
}

static node_t *get_neighbors(sol_t *sol, node_t *current_node, int *n)
{
    int x = current_node->pos.x;
    int y = current_node->pos.y;
    cell_t to_check[] = {
        { x, y - 1 }, { x + 1, y }, { x, y + 1 }, { x - 1, y }
    };
    node_t neighbors[4];
    node_t *result;

    for (int i = 0; i < 4; i++)
        if (to_check[i].x >= 0 && to_check[i].x < sol->x    \
        &&  to_check[i].y >= 0 && to_check[i].y < sol->y    \
        &&  sol->map[to_check[i].x][to_check[i].y] == PATH) {
            printf("(%d %d)\n", to_check[i].x, to_check[i].y);
            neighbors[(*n)].pos.x   = to_check[i].x;
            neighbors[(*n)++].pos.y = to_check[i].y;
        }
    result = malloc(sizeof(node_t) * (*n));
    for (int i = 0; i < (*n); i++)
        result[i] = neighbors[i];
    printf("%d\n", *n);
    return (result);
}

#include <time.h>
void solve_maze(sol_t *sol, cell_t start, cell_t end)
{
    // ------------------------------------------------------------------------------------ //
    struct timespec *pause;pause = malloc(sizeof(struct timespec));pause->tv_nsec = 250000000;
    // ------------------------------------------------------------------------------------ //
    node_t start_node, end_node;
    stack_man_t *st;

    st = st_initialize(0);
    init_node(&start_node, &end_node, &start, &end);
    st_push(st, start_node);
    while (!st_isempty(st)) {
        node_t current_node;
        int n = 0;

        current_node = st_pop(st);
        printf("vis: %d\n", current_node.visited == true);
        printf("(%d %d) =?= (%d %d)\n", current_node.pos.x, current_node.pos.y, end.x, end.y);
        if (check_if_goal_reached(&current_node, &end))
            break;
        node_t *neighbors = get_neighbors(sol, &current_node, &n);
        for (int i = 0; i < n; i++) {
            current_node.visited = true;
            neighbors[i].parent = &current_node;
            // neighbors[i].visited = true;
            st_push(st, neighbors[i]);
        }
        // -------------------------- //
        // for (int i = 0; i < sol->y; i++)
        //     printf("%s\n", sol->map[i]);
        nanosleep(pause, NULL);
        // printf("\e[1;1H\e[2J");
        // -------------------------- //
    }
    backtrack(sol, &(st->top->node));
    st_destroy(st);
}
