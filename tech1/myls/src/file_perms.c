/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** File filemode
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

void file_perms(mode_t ft)
{
    my_putchar((ft & S_IRUSR) ? 'r'  : '-' );
    my_putchar((ft & S_IWUSR) ? 'w'  : '-' );
    my_putchar((ft & S_IXUSR) ? 'x'  : '-' );
    my_putchar((ft & S_IRGRP) ? 'r'  : '-' );
    my_putchar((ft & S_IWGRP) ? 'w'  : '-' );
    my_putchar((ft & S_IXGRP) ? 'x'  : '-' );
    my_putchar((ft & S_IROTH) ? 'r'  : '-' );
    my_putchar((ft & S_IWOTH) ? 'w'  : '-' );
    my_putstr ((ft & S_IXOTH) ? "x " : "- ");
    return;
}
