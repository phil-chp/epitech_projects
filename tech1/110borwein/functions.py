##
## EPITECH PROJECT, 2021
## 110borwein (Workspace)
## File description:
## functions
##

from sys import exit
from math import sin


def integ_product(x, n):
    """Calculates the integral"""
    res = 1.0

    if x != 0:
        for i in range(n + 1):
            res *= (sin(x / ((2 * i) + 1)) / (x / ((2 * i) + 1)))
    return res


def middlepoint(n, sup, inf):
    """Borwein integrals using the Midpoint rule"""
    h = 1 / 2
    res = 0.0

    if sup or inf:
        pass
    for x in range(0, 10000, 1):
        res += integ_product(h * (x + 0.5), n)
    res *= h
    return res


def trapezoidal(n, sup, inf):
    """Borwein integrals using the Trapezoidal rule"""
    h = 1 / 2
    res = 0.0

    for x in range(1, 10000, 1):
        res += integ_product(x * h, n)
    res = (h / 2) * (integ_product(sup,  n) + integ_product(inf, n) + 2 * res)
    return res


def simpson(n, sup, inf):
    """Borwein integrals using the Simpson's rule"""
    temp = [.0, .0]
    h = 1 / 2

    for i in range(1, 10000):
        temp[0] += integ_product(i * h, n)
    for i in range(0, 10000):
        temp[1] += integ_product((h + i) * h, n)
    res = h / 6 * (integ_product(sup, n) + integ_product(inf, n))
    res += 2 * (h / 6) * (temp[0] + 2 * temp[1])
    return res


def get_functions():
    """ Create the function pointer to call the above functions """
    functions = {
        0: middlepoint,
        1: trapezoidal,
        2: simpson
    }
    return functions


def prints(n):
    """ Returns the correct message for each function """
    strs = ["Midpoint:", "Trapezoidal:", "Simpson:"]
    return strs[n]
