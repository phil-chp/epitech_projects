/*
** EPITECH PROJECT, 2021
** corewar (Workspace)
** File description:
** my_str_to_hex
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "shared.h"
#include "my.h"

int hex_to_deci(char *hex)
{
    int decimal = 0;
    int val = 0;
    int i = 0;
    int len;

    len = my_strlen(hex) - 1;
    for (; hex[i] != '\0'; i++, len--) {
        if (hex[i] >= '0' && hex[i] <= '9')
            val = hex[i] - 48;
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            val = hex[i] - 97 + 10;
        decimal += (val * pow(16, len));
    }
    return (decimal);
}
