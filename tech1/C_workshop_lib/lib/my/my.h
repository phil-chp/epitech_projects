/*
** EPITECH PROJECT, 2020
** My
** File description:
** My Lib Protos
*/

#ifndef LIB_H_
#define LIB_H_

void my_putchar(char);
char *my_strstr(char *, char *);
int my_isneg(int);
int my_strcmp(char *, char *);
int my_put_nbr(int);
int my_strncmp(char *, char *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
int my_strlen(char *);
char *my_strcapitalize(char *);
int my_getnbr(char *);
int my_str_isalpha(char *);
void my_sort_int_array(int *, int);
int my_str_isnum(char *);
int my_compute_power_rec(int, int);
int my_str_islower(char *);
int my_compute_square_root(int);
int my_str_isupper(char *);
int my_is_prime(int);
int my_str_isprintable(char *);
int my_find_prime_sup(int);
int my_showstr(char *);
char *my_strcpy(char *, char *);
int my_showmem(char *, int);
char *my_strncpy(char *, char *, int);
char *my_strcat(char *, char *);
char *my_revstr(char *);
char *my_strncat(char *, char *, int);
char *my_strdup(char const *);

void my_is_sorting(int, int, int *);
char **my_str_to_word_array(char const *);
int my_char_isprintable(char const);
char to_hex(int, char const *, int);

#endif /* LIB_H_ */
