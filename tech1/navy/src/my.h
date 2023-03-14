/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

int my_getnbr(char const *);
int my_strlen(char const *);
int my_putstr(char const *);
void my_putchar(char);
int my_put_nbr(int);
char *my_strcat(char *, char const *);
char *my_strdup(char const *);
int my_strcmp(char const *, char const *);
char *my_strupcase(char *);
char *my_revstr(char *);
char *my_strcpy(char *, char const *);

char *my_get_str(int);
void my_put_tbl(const char **);

#ifndef LPRINTF_H_
#define LPRINTF_H_

int my_lprintf(char const *expr, ...);

#endif /* !LPRINTF_H_ */
#endif /* !MY_H_ */
