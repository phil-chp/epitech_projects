/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** My_ls function
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "errors.h"
#include "lib.h"
#include "my.h"

void my_ls(char *file, int *index)
{
    struct stat ft;

    if (lstat(file, &ft) == -1)
        FILE_NOT_FOUND;
    if (index[0] == 1) {
        if (!(ft.st_mode & S_IRUSR) && file[0] != '.')
            PERM_DENIED;
        char type = file_type(ft.st_mode);
        file_perms(ft.st_mode);
        file_hard_link(ft.st_nlink);
        file_uid(ft.st_uid);
        file_gid(ft.st_gid);
        if (type == 'y') {
            file_major(ft.st_rdev);
            file_minor(ft.st_rdev);
        } else
            file_size(ft.st_size);
        file_date_time(ft.st_mtime);
    }
    return;
}
