/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** File Major
*/

#include <sys/sysmacros.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

void file_major(dev_t file)
{
    my_putnbr(major(file));
    my_putstr(", ");
    return;
}
