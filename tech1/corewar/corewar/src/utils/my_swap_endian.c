/*
** EPITECH PROJECT, 2021
** corewar (Workspace)
** File description:
** little_endian to big_endian converter
** takes an int and swaps it's bytes to conform to big endian
** ie:
**   [0x00 0x00 0x00 0x17]  -> [0x17 0x00 0x00 0x00]
*/

#include <stddef.h>
#include "op.h"

int my_swap_endian(int c)
{
    endian_t temp;
    char mem;

    temp.n = c;
    for (size_t i = 0, j = 3; i < 3; i++, j--) {
        mem = temp.c[i];
        temp.c[i] = temp.c[j];
        temp.c[j] = mem;
    }
    return (temp.n);
}
