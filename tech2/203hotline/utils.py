##
## EPITECH PROJECT, 2022
## 203hotline
## File description:
## 203hotline
##

from math import *
from sys import argv, stderr, exit

WORK_TIME = 28800

def print_usage():
    """ Prints usage """
    print("USAGE")
    print("\t./202unsold\t [n k | d]")
    print("DESCRIPTION")
    print("\tn\tn value for the computation of C(n, k)")
    print("\tk\tk value for the computation of C(n, k)")
    print("\td\taverage duration of calls (in seconds)")
    exit(0)


def error(message):
    """ Given a error message, prints it and exits with error code """
    print(f"{argv[0]}: {message}", file=stderr)
    exit(84)


def get_coeff(n, k):
    if k > n:
        error("Invalid coefficient.")
    return factorial(n) // (factorial(k) * factorial(abs(n - k)))


def get_charge(d):
    return d / WORK_TIME


def get_call_nb(d):
    return WORK_TIME / d


def print_spacer(i):
    if i % 5 == 0 and i > 0:
        print("\n", end="")
    elif i > 0:
        print("\t", end="")
