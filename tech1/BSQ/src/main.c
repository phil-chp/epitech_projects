/*
** EPITECH PROJECT, 2020
** Main
** File description:
** Main file
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "errors.h"
#include "struct.h"

static void error_handling(t_table *table, char *buff, int file, int ac)
{
    int bs = 0;
    int len = 0;

    (table == NULL) && (MEM_ERROR, exit(MEMORY), 0);
    (ac != 2) && (SYNTAX_ERROR, exit(WRONG_PARAMS), 0);
    for (int i = 0; buff[i]; i++)
        (buff[i] == '\n') && (bs++);
    (file == -1 || bs < 1) && (ERROR, exit(NOT_A_FILE), 0);
    for (int i = 0; buff[i] != '\n'; i++) {
        len += (buff[i] - 48);
        len *= 10;
    }
    if (len != 0) len /= 10;
    (len != bs) && (ERROR, exit(WRONG_PARAMS), 0);
    return;
}

int main(int ac, char **av)
{
    t_table *table = malloc(sizeof(t_table));
    (table == NULL) && (MEM_ERROR, exit(84), 0);
    int file = open(av[1], O_RDONLY);
    struct stat st;
    int size;
    char *buff;
    int len;

    (fstat(file, &st) == -1) && (ERROR, exit(84), 0);
    size = st.st_size;
    buff = malloc(sizeof(char) * size);
    len = read(file, buff, size);
    buff[size - 1] = '\0';
    (len < 0) && (exit(84), 0);
    error_handling(table, buff, file, ac);
    new_table(table, buff);
    free(buff);
    bsq(table);
    close(file);
    return (0);
}
