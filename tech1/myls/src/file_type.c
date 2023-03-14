/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** File Type
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "lib.h"
#include "my.h"

char file_type(mode_t ft)
{
    int n = 0;

    (S_ISREG (ft)) ? (my_putstr("-")     ) : (0);
    (S_ISDIR (ft)) ? (my_putstr("d")     ) : (0);
    (S_ISCHR (ft)) ? (my_putstr("c"), n++) : (0);
    (S_ISBLK (ft)) ? (my_putstr("b"), n++) : (0);
    (S_ISLNK (ft)) ? (my_putstr("l")     ) : (0);
    (S_ISFIFO(ft)) ? (my_putstr("p")     ) : (0);
    (S_ISSOCK(ft)) ? (my_putstr("s")     ) : (0);
    return (n != 0) ? ('y')                : ('n');
}
