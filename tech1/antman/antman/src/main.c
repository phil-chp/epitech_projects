/*
** EPITECH PROJECT, 2021
** antman
** File description:
** Antman - compressor
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/assets.h"
#include "../../include/my.h"

buff_t *antman_manager(char *file_str);

void create_compressed(buff_t *buff, char *file_str);

int main(int ac, char **av)
{
    buff_t *buff;
    char *file_str;
    int count;

    if (ac != 3) return (84);
    if (my_getnbr(av[2]) < 1 || my_getnbr(av[2]) > 3) return (84);
    file_str = read_file(av[1]);
    if (!file_str) return (84);
    buff = antman_manager(file_str);
    if (!buff) return (84);
    for (count = 0; buff->rep[count] != 0; count++);
    bubble_sort_array(count, buff);
    create_compressed(buff, file_str);
    free_content(buff, file_str);
    return (0);
}
