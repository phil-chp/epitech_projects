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

void file_minor(dev_t file)
{
    my_putnbr(minor(file));
    my_putchar(' ');
    return;
}
