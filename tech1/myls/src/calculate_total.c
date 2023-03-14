/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** calculate_total
*/

#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include "errors.h"
#include "lib.h"
#include "my.h"

void calculate_total(char *file)
{
    DIR *file_desc = opendir(file);
    struct dirent *files;
    struct stat ft;
    int total = 0;

    while ((files = readdir(file_desc)) != NULL) {
        if (lstat(file, &ft) == -1)
            FILE_NOT_FOUND;
        total += ft.st_blocks / 2;
        if (files->d_name[0] == '.')
            total -= ft.st_blocks / 2;
    }
    my_putstr("total ");
    my_putnbr(total);
    my_putchar('\n');
}
