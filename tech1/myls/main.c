/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** Main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "errors.h"
#include "lib.h"
#include "my.h"

static void path_name(char **av, int n, int adv, int *index)
{
    if ((index[5] - adv > 1 || n != 0) && index[0] == 1) {
        (n != 0) ? (my_putstr("\n")) : 0;
        my_putstr(av[adv]);
        my_putstr(":\n");
    }
}

static int test_params(char **av, int *index)
{
    int adv = 0;
    int c = 1;

    for (int i = 1; i <= index[5] && av[i][0] == '-'; i++) {
        (av[i] != NULL && my_strlen(av[i]) < 2) && (PARAM_ERROR, 0);
        char *value = av[i];
        for (; c < my_strlen(value) && av[i][0] == '-'; c++) {
            (av[i][c] == 'l') ? (index[0] = 1,    (c == 1) && (adv++)    ) : \
            (av[i][c] == 'd') ? (index[1] = 1,    (c == 1) && (adv++)    ) : \
            (av[i][c] == 'R') ? (index[2] = 1,    (c == 1) && (adv++)    ) : \
            (av[i][c] == 't') ? (index[3] = 1,    (c == 1) && (adv++)    ) : \
            (av[i][c] == 'r') ? (index[4] = 1,    (c == 1) && (adv++)    ) : \
            (PARAM_ERROR);
        }
        c = 1;
    }
    return (adv);
}

static void read_file(char **av, DIR *file_desc, int *index, int adv)
{
    char path[256];
    int n = my_strlen(path) - 1;
    struct dirent *files;

    for (int step = 0;(files = readdir(file_desc)) != NULL; ) {
        my_strcpy(path, av[adv]);
        if (files->d_name[0] != '.') {
            (path[n] != '/') && (my_strcat(path, "/"), 0);
            my_strcat(path, files->d_name);
            my_ls(path, index);
            (index[0] == 0 && step != 0) && (my_putchar(' '), 0);
            my_putstr(files->d_name);
            (index[0] == 1) && (my_putchar('\n'), 0);
            step++;
        }
    }
    (adv < index[5] - 1 && index[0] == 1) && (my_putstr("\n"), 0);
    (adv < index[5] - 1 && index[0] == 0) && (my_putstr("\n\n"), 0);
    (index[0] == 1) && (index[0] = 2);
}

int main(int ac, char **av)
{
    int index[] = {0, 0, 0, 0, 0, ac};
    int adv = test_params(av, &*index) + 1;
    DIR *file_desc;

    for (int n = 0; adv < ac; adv++, n++) {
        file_desc = opendir(av[adv]);
        (index[1] == 1) ? (file_desc = NULL) : 0;
        if (file_desc != NULL && index[1] != 1) {
            path_name(av, n, adv, index);
            (index[0] == 1) ? (calculate_total(av[adv])) : 0;
            read_file(av, file_desc, index, adv);
        } else {
            my_ls(av[adv], index);
            my_putstr(av[adv]);
            (adv < ac - 1 && index[0] == 0) && (my_putchar(' '), 0);
            (adv < ac - 1 && index[0] == 1) && (my_putchar('\n'), 0);
        }
    }
    (index[0] != 2) && (my_putchar('\n'), 0);
    closedir(file_desc);
    return (0);
}
