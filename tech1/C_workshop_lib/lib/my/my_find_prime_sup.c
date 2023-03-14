/*
** EPITECH PROJECT, 2020
** My Find Prime Sup
** File description:
** Find Prime Numbers
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (nb; ; nb++)
        if (my_is_prime(nb) == 1)
            return (nb);
}
