##
## EPITECH PROJECT, 2022
## Groundhog (Workspace)
## File description:
## utils
##

from sys import stderr, argv
from math import sqrt

SUCCESS_CODE = 0
ERROR_CODE   = 84
WEIRD_TRESHOLD = 1.89

def usage():
    """ Prints usage and exits """
    print("USAGE")
    print("\t./groundhog period")
    print("DESCRIPTION")
    print("\tperiod\tthe number of days defining a period")
    exit(SUCCESS_CODE)


def error(msg):
    """ Prints an error message and exits with error """
    print(f"{argv[0]}: {msg}", file=stderr)
    exit(ERROR_CODE)


def argument_parsing(argv):
    """ Given argv either prints usage / error / or returns the period """
    help = (len(argv) == 2 and (argv[1] == "-h" or argv[1] == "--help"))

    if len(argv) != 2 or help:
        usage()
    try:
        period = int(argv[1])
    except (ValueError, TypeError) as e:
        error(e)
    if period <= 0:
        error("period must be strictly positive")
    return period

# ----------------------------------- Math ----------------------------------- #

def moving_average(values, period):
    """ Returns the moving average of a list of values """
    avrg = values[-period:]
    return sum(avrg) / len(avrg)


def deviation(values, period, average=None):
    """ Returns the deviation of a list of values """
    if period == 0:
        return 0
    if average is None:
        average = moving_average(values, period)
    d = 0

    for value in values[-period:]:
        d += (value - average) ** 2
    return sqrt(d / period)


# def bollinger(average, deviation):
#     """ Returns the bollinger (upper, lower) bounds as a tuple """
#     upper = average + WEIRD_TRESHOLD * deviation
#     lower = average - WEIRD_TRESHOLD * deviation
#     return (upper, lower)
