/*
** EPITECH PROJECT, 2020
** target str
** File description:
** target
*/

#include <unistd.h>
#include <stdlib.h>
#include "mymac.h"
#include "my.h"
#include "pers.h"

char *targetstr(char *str, int pos, int l)
{
    char list[] = "0123456789";
    str[pos] = list[l];
    return (str);
}
