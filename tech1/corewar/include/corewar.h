/*
** EPITECH PROJECT, 2020
** corewar.h
** File description:
** corewar header
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include "my.h"
#include "op.h"

typedef struct code_s {
    __u_char f;
    __u_int *params;
    args_type_t types[4];
} code_t;

typedef struct champions_s {
    __u_int pos :12;
    header_t content;
    char *code_byte;
    size_t t_cycle;
    bool state;
    code_t code;
    size_t id;
    int regs[16];
    struct champions_s *next, *head, *prev;
    struct champions_s *f_next, *f_head, *f_prev;
} champs_t;

typedef struct corewar_s {
    __u_char *arena;
    champs_t *champs;
    char *alive;
    char teams;
    bool carry;
} corewar_t;

// - - - // - - -     MAIN     - - - // - - - //
bool corewar(corewar_t *cw);
// - - - // - - - // - -- - // - - - // - - - //

//

// - - - // - - -     INIT     - - - // - - - //
bool init_champs(corewar_t *cw, char **params);
bool init_alive_list(corewar_t *cw);
bool fill_arena(champs_t **champs, __u_char **arena);
void init_fork(champs_t *child, champs_t *parent);
// - - - // - - - // - -- - // - - - // - - - //

//

// - - - // - - -    DESTROY   - - - // - - - //
void destroy_features(corewar_t *cor);
void destroy_code_byte_elements(char *temp, char **res);
// - - - // - - - // - -- - // - - - // - - - //

//

// - - - // - - -     UTILS    - - - // - - - //
bool refresh_champions(champs_t *iter, __u_char **arena);
bool handle_ending(char teams, champs_t **champs);
void who_is_alive(corewar_t *cw);
void ping_alive(champs_t *iter);
__u_int get_code_from_code_bytes(__u_char **arena, code_t *code, __u_int pos);
bool check_dot_cor(char *param, size_t cor);

int hex_to_deci(char *hex);
char **my_op_code_converter(char *op_code);
int my_swap_endian(int c);
// - - - // - - - // - -- - // - - - // - - - //

//

// - - - // - - - INSTRUCTIONS - - - // - - - //
void  f_live(corewar_t *cw, champs_t *iter);
void    f_ld(corewar_t *cw, champs_t *iter);
void    f_st(corewar_t *cw, champs_t *iter);
void   f_add(corewar_t *cw, champs_t *iter);
void   f_sub(corewar_t *cw, champs_t *iter);
void   f_and(corewar_t *cw, champs_t *iter);
void    f_or(corewar_t *cw, champs_t *iter);
void   f_xor(corewar_t *cw, champs_t *iter);
void  f_zjmp(corewar_t *cw, champs_t *iter);
void   f_ldi(corewar_t *cw, champs_t *iter);
void   f_sti(corewar_t *cw, champs_t *iter);
void  f_fork(corewar_t *cw, champs_t *iter);
void   f_lld(corewar_t *cw, champs_t *iter);
void  f_lldi(corewar_t *cw, champs_t *iter);
void f_lfork(corewar_t *cw, champs_t *iter);
void   f_aff(corewar_t *cw, champs_t *iter);
// - - - // - - - // - -- - // - - - // - - - //

#endif /* COREWAR_H_ */
