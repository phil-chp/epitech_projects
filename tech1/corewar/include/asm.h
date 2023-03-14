/*
** EPITECH PROJECT, 2020
** asm.h
** File description:
** corewar header
*/

#ifndef ASM_H_
#define ASM_H_

#define ERROR           84
#define ERROR_VERIF     -1
#define FILE_NOT_EXIST  -2
#define IS_DIRECTORY    -3
#define FILE_EMPTY      -4
#define ERROR_OPEN      -5
#define ERROR_MEM       -6
#define ERROR_READ      -7
#define ERROR_CLOSE     -8
#define ERROR_INIT      -9
#define ERROR_WRITE     -10

#include "my.h"
#include "op.h"

typedef struct asmb_s {
    char **tab;
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    char *command;
} asmb_t;

typedef struct bitchar_s {
    unsigned char c :2;
} bitchar_t;

typedef union binary {
    struct {
        unsigned char duo1 :2;
        unsigned char duo2 :2;
        unsigned char duo3 :2;
        unsigned char duo4 :2;
    };
    struct {
        unsigned char bit1 :1;
        unsigned char bit2 :1;
        unsigned char bit3 :1;
        unsigned char bit4 :1;
        unsigned char bit5 :1;
        unsigned char bit6 :1;
        unsigned char bit7 :1;
        unsigned char bit8 :1;
    };
    unsigned char c;
} binary_u;

typedef union number {
    struct {
        unsigned char char1;
        unsigned char char2;
        unsigned char char3;
        unsigned char char4;
    };
    unsigned int nb;
} number_u;

/* SRC/get_command. */
char get_bin(char **args, int nb, int index);
int get_arg(char **command, int temp, int *size, char *arg);
int get_args_size(char **command, char **word, int *size);
int get_opt(char **com, char **words, int *size);
int get_command(asmb_t *asmm);

/* SRC/get_name_and_comment.c */
int get_name(asmb_t *asmm, header_t *header);
int get_comment(asmb_t *asmm, header_t *header);

/* SRC/print_usage.c */
void print_usage(void);

/* SRC/read_and_check */
int asm_to_cor(asmb_t *asmm, header_t *header, int size, char *path);
int read_and_check(asmb_t *asmm, char *path);
int my_swap_endian(int c);

/* SRC/main.c */
int compare_word(char *str);
char instruct_forest(char *str);
int get_asm(asmb_t *asmm, header_t *header, char *path);
int manage_asmm(char *path);

/* COREWAR/utils */
int my_swap_endian(int c);

#endif /* ASM_H_ */
