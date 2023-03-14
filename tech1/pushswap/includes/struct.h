/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** Main structures
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct sort_s {
    int n;
    struct sort_s *next, *prev;
} sort_t;

typedef struct index_s {
    sort_t *tail;
} index_t;

void sorter(int, int *);

int link_add(sort_t **, int);
void link_destroy(sort_t **, index_t *);
void link_build(sort_t **, index_t **, int *, int);
sort_t *link_remove(sort_t *);
void sorting_algo(sort_t *, index_t *, int);

void val_swap(sort_t *, int);
sort_t *val_move(sort_t *, index_t *);
void val_rotate(index_t *, int, int);

#endif /* STRUCT_H_ */
