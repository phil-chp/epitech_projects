/*
** EPITECH PROJECT, 2021
** libstack
** File description:
** libstack header file
*/

#ifndef STACK_H_
#define STACK_H_

#include <stddef.h>

#ifndef SOLVER_H_

typedef struct cell_s {
    int x;
    int y;
} cell_t;

typedef struct node_s {
    struct node_s *parent;
    cell_t pos;
    int g;
    int h;
    int f;
} node_t;

#endif /* SOLVER_H_ */

typedef struct stack_s {
    node_t node;
    struct stack_s *prev;
} stack_t;

typedef struct stack_man_s {
    int count;
    int max;
    stack_t *top;
} stack_man_t;

// - - - Stack prototypes - - - //

stack_man_t *st_initialize(int max);

int          st_push(stack_man_t *st, node_t node);
node_t       st_pop(stack_man_t *st);

int          st_isempty(stack_man_t *st);
int          st_isfull(stack_man_t *st);

void         st_print(stack_t *item);

void         st_flush(stack_man_t *st);
void         st_destroy(stack_man_t *st);

int          st_match(stack_man_t *st, cell_t c);

void         st_print(stack_t *item);

// - - - - - - -  - - - - - - - //

#endif /* STACK_H_ */
