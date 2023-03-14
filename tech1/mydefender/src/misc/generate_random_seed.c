/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** generate_random_seed
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void generate_random_seed(void)
{
    unsigned seed;
    int fd;
    ssize_t t;

    fd = open("/dev/urandom", O_RDONLY);
    if ((t = read(fd, &seed, sizeof(seed))) == -1) {}
    srand(seed);
    close(fd);
}
