##
## EPITECH PROJECT, 2022
## Visual Studio Live Share (Workspace)
## File description:
## distribution
##

from math import factorial, exp

from utils import get_coeff, get_charge, get_call_nb, print_spacer

REP_TOT = 3500


def binomial(k, n, p):
    """ Binomial distribution """
    return (get_coeff(n, k) * (p ** k) * ((1 - p) ** (n - k)))


def distribution_binomial(d):
    """ Given n and k calculates the binomial distribution """
    overload = 0
    charge = get_charge(d)
    call_nb = get_call_nb(d)

    for i in range(51):
        print_spacer(i)
        res = binomial(i, REP_TOT, charge)
        overload += res if i <= 25 else 0
        print(f"{i} -> {res:.3f}", end="")
    return (1 - overload) * 100


# ---------------------------------------------------------------------------- #


def poisson(k, n, charge):
    """ Poisson distribution """
    return ((n * charge) ** k / factorial(k)) * exp(-n * charge)


def distribution_poisson(d):
    """ Given n and k calculates the binomial distribution """
    overload = 0
    charge = get_charge(d)

    for i in range(51):
        print_spacer(i)
        res = poisson(i, REP_TOT, charge)
        overload += res if i <= 25 else 0
        print(f"{i} -> {res:.3f}", end="")
    return (1 - overload) * 100
