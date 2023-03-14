/*
** EPITECH PROJECT, 2020
** My Is Prime
** File description:
** Checks if number is prime
*/

int  my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
