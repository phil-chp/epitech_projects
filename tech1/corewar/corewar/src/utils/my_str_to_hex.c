/*
** EPITECH PROJECT, 2021
** corewar (Workspace)
** File description:
** my_str_to_hex
*/

#include <stdlib.h>
#include <unistd.h>
#include "shared.h"

char *my_str_to_hex(char *str, int size)
{
    char *res;
    hex_u hex;

    res = malloc(sizeof(char) * (size * 2 + 1));
    for (register ssize_t i = 0, j = 0; i < size; ) {
        hex.n = str[i++];
        res[j++] = HEX(hex.x2);
        res[j++] = HEX(hex.x1);
    }
    res[size * 2] = '\0';
    return (res);
}
