/*
** EPITECH PROJECT, 2021
** antman
** File description:
** Giantman - decompressor
*/

#include <stdio.h>
#include "../../include/assets.h"
#include "../../include/my.h"

buff_t *giantman_manager(char *file_str);

void create_decompressed(buff_t *buff);

int main(int ac, char **av)
{
    char *file_str;
    buff_t *buff;

    if (ac != 3) return (84);
    if (my_getnbr(av[2]) < 1 || my_getnbr(av[2]) > 3) return (84);
    file_str = read_file(av[1]);
    if (!file_str) return (84);
    buff = giantman_manager(file_str);
    if (!buff) return (84);
    create_decompressed(buff);
    free_content(buff, file_str);
    return (0);
}
