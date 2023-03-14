/*
** EPITECH PROJECT, 2021
** libstack
** File description:
** libstack header file
*/

#ifndef STACK_H_
    #define STACK_H_

    #include <stddef.h>

typedef struct stack_s {
    void *data;
    struct stack_s *prev;
} stack__t;

typedef struct stack_man_s {
    int count;
    int max;
    stack__t *top;
} stack_man_t;

// - - - Stack prototypes - - - //

stack_man_t *st_initialize(int max);

int st_push(stack_man_t *st, void *data);
void *st_pop(stack_man_t *st);

int st_isempty(stack_man_t *st);
int st_isfull(stack_man_t *st);

void st_flush(stack_man_t *st);
void st_destroy(stack_man_t *st);

// - - - - - - -  - - - - - - - //

#endif /* STACK_H_ */
