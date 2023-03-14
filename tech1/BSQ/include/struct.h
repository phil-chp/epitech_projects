/*
** EPITECH PROJECT, 2020
** Structure
** File description:
** This structure contians the values for the table.
*/

#ifndef _STRUCT_H_
#define _STRUCT_H_

#define BUFF_SIZE  4096

typedef struct s_table {
    char **board;
    int **temp;
    int x;
    int y;
} t_table;

#define SIZE ((table->temp[x - 1][y] == 0               \
                || table->temp[x][y - 1] == 0           \
                || table->temp[x - 1][y - 1] == 0       \
                || table->temp[x][y] == 0) ? (0) : (1))

#define LEN (y >= table->y) && (x++, y = 0)
#define NEXT (y >= table->y) && (x++, y = 1)

void bsq(t_table *);

void populate_by_weight(t_table *);
void place_square(t_table *);
void search_pos_y(t_table *);
void search_pos_x(t_table *);

void get_y(t_table *, char *);
int get_x(t_table *, char *);
int new_table(t_table *, char *make);

void free_memory(t_table *);

#endif /* _STRUCT_H_ */
