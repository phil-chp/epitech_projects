/*
** EPITECH PROJECT, 2020
** prepare p
** File description:
** module for multiplication
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mymac.h"
#include "pers.h"

char *prep(char *s)
{
    char *p = malloc(sizeof(char)*(my_strlen(s)+2));
    if (s[0] == 45)
        p = onlynumb(s);
    else
        (p = s);
    p = retirezero(p);
    return p;
}
