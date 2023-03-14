/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#ifndef MY_H_

#include <unistd.h>
#include "my.h"

#endif /* MY_H_ */

#include <ncurses.h>

#define ERROR(str)  curs_set(1), write(2, str, my_strlen(str)), exit(84)

typedef struct movement_s {
    int key;
    int x;
    int y;
    char pos;
    char old_pos;
}   mov_t;

typedef struct goals_s {
    struct goals_s *next, *prev, *head;
    int state;
    int x;
    int y;
}   goals_t;

// *** Init *** //
mov_t *init_mov(void);
int *init_ncurses(mov_t *mov, char **map);
goals_t *init_goals(char c);

// *** Input *** //
void get_element_pos(mov_t *mov, char c);
void handle_move(mov_t *mov);

// *** Misc *** //
int **find_all_elements(char c, int *count);
void check_goals(goals_t *goals);
int check_boxes(int *dim);

// *** Map *** //
char *read_file(char *file);
int *set_map(char **path);

// *** Screen *** //
int check_screen_size(mov_t *mov, int *dim, char *map, int n);

// *** End *** //
void destroy_all(mov_t *mov, goals_t *goals, int *dim, char *map);

#endif /* SOKOBAN_H_ */
