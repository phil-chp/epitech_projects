##
## EPITECH PROJECT, 2022
## 203hotline
## File description:
## 203hotline
##

from math import *
from sys import argv, stderr, exit

# ----------------------------------- Misc ----------------------------------- #


def print_usage():
    """ Prints usage """
    print("USAGE")
    print("\t./204ducks a")
    print("DESCRIPTION")
    print("\ta\tconstant")
    exit(0)


def error(message):
    """ Given an error message, prints it and exits with error code """
    print(f"{argv[0]}: {message}", file=stderr)
    exit(84)


# ----------------------------------- Maths ---------------------------------- #


def average(a):
    return 3 * (2 + a) / 8


def deviation(a):
    return sqrt(((7 / 16) * (3 * a + 2)) - ((9 / 64) * ((a + 2) ** 2)))