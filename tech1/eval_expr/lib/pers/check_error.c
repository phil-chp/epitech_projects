/*
** EPITECH PROJECT, 2020
** check error
** File description:
** error definition
*/

#include <unistd.h>
#include <stdlib.h>
#include "mymac.h"
#include "my.h"
#include "pers.h"

void check_error(char *p2)
{
    if (my_strlen(p2) == 1 && p2[0] == '0') {
        ERROR;
        exit(84);
    }
}
