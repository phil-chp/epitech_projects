/*
** EPITECH PROJECT, 2021
** antman
** File description:
** my lib prototypes
*/

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
int my_putstr(char const *str);
int my_putnbr(int nb);
void my_put_tbl(const char **tbl);
int my_strlen(char const *str);
char *my_revstr(char *str);
char *my_strdup(char const *src);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);

#ifndef MY_LPRINTF_H_
#define MY_LPRINTF_H_

int my_lprintf(char const *expr, ...);

#endif /* !MY_LPRINTF_H_ */

#endif /* !MY_H_ */
