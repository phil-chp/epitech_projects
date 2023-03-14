/*
** EPITECH PROJECT, 2020
** myfindprimesup
** File description:
** disp fisrt nbp > parameter
*/

int my_is_prime(int nb)
{
    int a = 0;

    if (nb<2)
        return (0);
    for (int i = 2; i <= nb - 1; i++) {
            if (nb % i == 0) {
                a++;
            }
    }
    if (a == 0) {
        return (1);
    }
    else
        return (0);
}
