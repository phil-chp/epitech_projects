/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** File Hard Link
*/

#include <sys/types.h>
#include "lib.h"
#include "my.h"

void file_size(off_t file)
{
    my_putnbr(file);
    my_putstr(" ");
    return;
}
