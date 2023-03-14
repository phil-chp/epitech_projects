/*
** EPITECH PROJECT, 2020
** Eval Expr Struct
** File description:
** Eval Expr Struct
*/

#ifndef EVAL_EXPR_STRUCT_H_
#define EVAL_EXPR_STRUCT_H_

#define IS_OPS (is_ops(eval, calc[i]) == 1)
#define IS_BASE (is_base(eval, calc[i]) == 1)

typedef struct s_eval
{
    char **base;
    char **ops;
    int len;
    char **temp;
}   t_eval;

void table(t_eval *, char *);
void make_table(t_eval *, char *, int);
void secure_zero(t_eval *);
void set_calc(t_eval *, char *);
char *minus_check(t_eval *, char *);
void check_minus(t_eval *);
int is_base(t_eval *, char);
int is_ops(t_eval *, char);
t_eval *new_eval(t_eval *, char *, char *, int);
void eval_expr(char *, char *, char *, unsigned int);
void values_check(t_eval *);
void my_trans_base(t_eval *, char *);

#endif /* EVAL_EXPR_STRUCT_H_ */
