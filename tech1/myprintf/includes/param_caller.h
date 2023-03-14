/*
** EPITECH PROJECT, 2020
** Param Caller
** File description:
** functions list pointer that calls every parameter and modifier
*/

#ifndef PARAM_CALLER_H_
#define PARAM_CALLER_H_

#include <stdarg.h>
#include "bsprintf.h"

void (*modifiers[5])(va_list, int, char const *) = {
                            hash,
                            check_plus_one,
                            check_space_one,
                            check_short_one,
                            check_long_one,
                            };

void (*parameters[13])() = {
                            my_putchar,
                            my_put_nbr,
                            my_put_nbr,
                            my_putstr,
                            my_put_uns_nbr,
                            my_put_oct_nbr,
                            my_put_uns_hex_nbr,
                            my_put_uns_hex_nbr_maj,
                            my_put_uns_bin_nbr,
                            my_show_oct_str,
                            my_put_address,
                            my_percent,
                            my_nothing
                            };

#endif /* PARAM_CALLER_H_ */
