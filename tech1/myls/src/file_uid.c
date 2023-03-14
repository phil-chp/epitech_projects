/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** File Hard Link
*/

#include <sys/types.h>
#include <pwd.h>
#include "lib.h"
#include "my.h"

void file_uid(uid_t file)
{
    struct passwd *name;

    name = getpwuid(file);
    my_putstr(name->pw_name);
    my_putstr(" ");
    return;
}
