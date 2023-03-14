/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

#ifndef MACRO_H_
#define MACRO_H_

#define MAP_W        18
#define MAP_H        10
#define MAP_SIZE     (MAP_W * MAP_H + 1)

#define INFO_FILE    "assets/info"
#define MAP_FILE     "assets/map"

#ifndef ERROR_H_
#define ERROR_H_

#define ERR_ARGS   write(2, "Navy: Wrong arguments\n", 23);

#endif /* ERROR_H_ */

#endif /* MACRO_H_ */

typedef struct plan_s {
    int pid1, pid2;
    int end;
    int limit;
    char *buff;
    char *pos1, *pos2;
    char **usr_map;
    char **arr_pos1, **arr_pos2;
    char **map_usr1, **map_usr2;
}   plan_t;

void handler(int);

int aread(plan_t *, char *);
int deterline(plan_t *);
plan_t *init_plan(int);

int map_maker(char *, plan_t *);
char **set_array(plan_t *, char **);
char *term_getline(void);
int aread_pos(plan_t *, char *, int);
char **my_copy_array(char **, char **);
char *orientation(char *, char *);
void add_element_map(char **, char *, char *);
int add_boat(char **, char **);
char **set_array_pos(char **, char **, char *);
char *term_getline(void);
char *bin_to_dec(char *);
char *dec_to_bin(char *);
void pos_handler(int);
char *receive_signal(int);
char *check_pos(plan_t *, char *, int);
int send_pos(plan_t *, char *, int, int);
void receive_pos(plan_t *, int );
void send_signal(int, char *);
char **add_shoot(char **, char *);
int play_usr1(plan_t *, char *, int);
int play_usr2(plan_t *, char *, int);

int write_file(char *, char *, int);
char *read_file(char *);

int usr1(plan_t *);
int usr2(plan_t *);

#endif /* LIB_H_ */
