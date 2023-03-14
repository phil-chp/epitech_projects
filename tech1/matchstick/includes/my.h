/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

void my_putchar(char);
int my_strlen(char const *str);
int my_putstr(char const *);
int my_puterr(char const *err);
int my_getnbr(char const *str);
char *my_strdup(char const *src);

int my_pow(int a, int b);
int my_revnbr(int num);
int my_int_len(int num);
char *my_get_str(int nb);
int append_to_nbr(int number, int to_append);
int *dec_array_to_base_array(int len, int array[len], int base);
void my_put_tbl(char **tbl);
char *my_strndup(char const c, int n);
char *my_strndup_frame(char const frame, char const fill, int n);
int my_lprintf(char const *expr, ...);

#endif /* MY_H_ */
