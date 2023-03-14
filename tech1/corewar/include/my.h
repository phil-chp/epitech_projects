/*
** EPITECH PROJECT, 2020
** myh
** File description:
** my header
*/

#ifndef MY_H_
#define MY_H_

#define PRINT_STR(str) write(1, (str), my_strlen((str)))

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdbool.h>

int my_putchar(char c);
int my_putstr(char const *str);
void miniprint(char *format, ...);
int my_strlen(const char *str);
void put_nbr(long long nb);
int my_getnbr(char *str);
char *my_strncpy(char *dest, char *src, unsigned int n);
char *my_strdup(const char *s);
int my_strcmp(const char *s1, const char *s2);
char **my_str_to_word_array(char *str, char *spaces);
char *split_nb_str(char *, int);
int counter(char **res);
char *my_getstr(int nb);
char *my_strcat(char *dest, char const *src);
int my_tablen(char **tab);
int my_strlen_n(const char *str, char c);

#endif /* MY_H_ */
