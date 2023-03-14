/*
** EPITECH PROJECT, 2020
** My Compute Square Root
** File description:
** Given a number Returns Square Root
*/

int my_compute_square_root(int nb)
{
    int sqrt;

    if (nb <= 0)
        return (0);
    for (sqrt = 0; sqrt * sqrt != nb; sqrt++) {
        if (sqrt > nb)
            return (0);
    }
    return (sqrt);
}
