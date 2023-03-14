/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** File Hard Link
*/

#include <sys/types.h>
#include <grp.h>
#include "lib.h"
#include "my.h"

void file_gid(gid_t file)
{
    struct group *name;

    name = getgrgid(file);
    my_putstr(name->gr_name);
    my_putstr(" ");
    return;
}
