/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "fractals.h"
#include "my.h"

static int check_chars(char c)
{
    if (c != '#' && c != '.' && c != '@')
        return (84);
    return (0);
}

static int check_map(char **av)
{
    char ***strs;
    int len;

    strs = malloc(sizeof(char **) * 2);
    for (int j = 2; j < 3; j++)
        for (int i = 0; av[j][i]; i++) 
            if (check_chars(av[j][i]) == 84) {
                return (84);
            }
    strs[0] = my_str_to_word_array(av[2]);
    strs[1] = my_str_to_word_array(av[3]);
    len = my_strlen(strs[0][0]);
    for (int j = 0; j < 2; j++)
        for (int i = 0; strs[j][i]; i++)
            if (len != my_strlen(strs[j][i]))
                return (84);
    free(strs);
    return (0);
}

static int check_errors(char **av)
{
    int nbr = my_getnbr(av[1]);
    if (nbr < 0 || nbr > 9) {
        write(2, "fractals: Bad arguments\n", 24);
        return (84);
    }
    if (check_map(av) == 84)
        return(84);
    return (0);
}

int main(int ac, char **av)
{
    int return_code = 0;
    
    if (ac != 4)
        return (84);
    return_code = check_errors(av);
    if (return_code != 84)
        return_code = handle_fractals(av);
    return (return_code);
}
