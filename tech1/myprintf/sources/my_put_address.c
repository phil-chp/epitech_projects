/*
** EPITECH PROJECT, 2020
** My put address
** File description:
** Puts addresses
*/

#include <unistd.h>
#include "bsprintf.h"

int my_strlen(char const *str);

void my_put_address(unsigned int address)
{
    my_putstr("0x");
    for (int i = 44; i >= 0; i -= 4)
        my_put_uns_hex_nbr(((address >> i) & 0xF));
    return;
}