/*
** EPITECH PROJECT, 2020
** My
** File description:
** my c lib
*/

#ifndef BSPRINTF_H_
#define BSPRINTF_H_

#include <stdarg.h>

int my_printf(const char *, ...);

void space_adder(unsigned int);
int indent_param(va_list, int, const char *, unsigned int *);

void hash(va_list, int, const char *);
int check_plus_one(va_list, int, const char *);
int check_short_one(va_list, int, const char *);
int check_space_one(va_list, int, const char *);
int check_long_one(va_list, int, const char *);

int my_putchar(const char);
int my_putstr(const char *);
int my_put_nbr(int);
void my_put_oct_nbr(int);
int my_show_oct_str(const char *);
void my_put_uns_hex_nbr(unsigned int);
void my_put_uns_hex_nbr_maj(unsigned int);
void my_put_uns_bin_nbr(unsigned int);
int my_put_uns_nbr(unsigned int);
int my_showstr(const char *);
void my_put_address(unsigned int);
int my_percent(void);
void my_nothing(void);

int my_strlen(const char *);
int my_put_short_nbr(short int);
int my_put_long_nbr(long int);
void my_put_long_uns_nbr(unsigned long);
int my_getnbr(const char *);
int my_str_isprintable(const char *);
char *my_get_str(int);
int my_char_isprintable(const char);
int my_int_len(int);

#endif /* BSPRINTF_H_ */