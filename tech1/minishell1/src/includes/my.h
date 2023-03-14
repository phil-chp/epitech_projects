/*
** EPITECH PROJECT, 2021
** minishell1 (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

void my_putchar(char);
int my_putnbr(const int);
int my_strlen(const char *);
int my_putstr(const char *);
int my_put_tbl(const char **);
int my_arraylen(char **);
char *my_strdup(char const *);
char *my_getenv(char *, int);
char **my_arraydup(char **);
char *my_strcat(char *, char *);
char *my_strupcase(char *);
char **my_str_to_word_array(char const *);
int my_strcmp(char const *, char const *);

int my_lprintf(char const *, ...);

#endif /* MY_H_ */
