/*
** EPITECH PROJECT, 2021
** B-CPE-210-NCE-2-1-stumper2-philippe.cheype
** File description:
** main
*/

#include "gameoflife.h"

int gameoflife(char **map, int itr);

static char *load_file_in_mem(char *filepath)
{
    struct stat st;

    if (stat(filepath, &st) == -1) return (NULL);
    if (!st.st_size)
        return (NULL);
    char *buf = malloc(sizeof(char) * st.st_size + 1);
    int fd = open(filepath, O_RDONLY);
    int size = read(fd, buf, st.st_size);
    if (size == -1) return (NULL);
    buf[st.st_size] = '\0';
    close(fd);
    return (buf);
}

int check_errors(char *buffer, int iteration)
{
    if (!buffer) {
        free(buffer);
        return (84);
    }
    if (iteration < 0) return (84);
    return (0);
}

int main(int ac, char **av)
{
    char **map;

    if (ac != 3) return (84);
    char *buffer = load_file_in_mem(av[1]);
    int iteration = my_getnbr(av[2]);
    if (check_errors(buffer, iteration) == 84) return (84);
    map = my_str_to_word_array_div(buffer, '\n');
    if (iteration == 0)
        my_print_map(map);
    else
        gameoflife(map, iteration);
    free(buffer);
    my_free_array(map);
    return (0);
}
