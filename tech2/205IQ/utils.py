##
## EPITECH PROJECT, 2022
## 205IQ
## File description:
## utils
##

from sys import argv, stderr, exit
from math import sin, pi, exp, sqrt
from Range import Range

# ----------------------------------- Misc ----------------------------------- #

def usage():
    """ Prints usage """
    print("USAGE")
    print("\t./205IQ u s [IQ1] [IQ2]")
    print("DESCRIPTION")
    print("\tu\tmean")
    print("\ts\tstandard deviation")
    print("\tIQ1\tminimum IQ")
    print("\tIQ2\tmaximum IQ")
    exit(0)


def error(message):
    """ Given an error message, prints it   """
    """ to stderr and exits with error code """
    print(f"{argv[0]}: {message}", file=stderr)
    exit(84)

# ----------------------------------- Maths ---------------------------------- #

SIMPSON_DEFAULT_ITER = 10_000

def integral_product(x, n):
    """ Calculates the integral product """
    res = 1.0

    if x != 0:
        for i in range(n + 1):
            res *= (sin(x / ((2 * i) + 1)) / (x / ((2 * i) + 1)))
    return res


def gaussian(x, mean, std):
    """ Applies the gaussian function """
    return 1 / (std * sqrt(2 * pi)) * exp(-pow((x - mean) / std, 2) / 2)


def simpson(r, mean, std, n=SIMPSON_DEFAULT_ITER):
    """ returns the Simpson's rule for n between min and max """
    """ (edited from 110borwein) """
    h = (r.max - r.min) / n
    res = gaussian(r.min, mean, std) + gaussian(r.max, mean, std)

    for i in range(0, n):
        res += 4 * gaussian(r.min + i * h + h / 2, mean, std)
    for i in range(1, n):
        res += 2 * gaussian(r.min + i * h, mean, std)
    return h / 6 * res * 100
