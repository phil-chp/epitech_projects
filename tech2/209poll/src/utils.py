##
## EPITECH PROJECT, 2022
## 205IQ
## File description:
## utils
##

from sys import argv, stderr, exit
from math import sqrt

# ----------------------------------- Misc ----------------------------------- #

def usage():
    """ Prints usage """
    print("USAGE")
    print("\t./207demography code [...]")
    print("DESCRIPTION")
    print("\tcode\tcountry code")
    exit(0)


def error(message):
    """ Given an error message, prints it   """
    """ to stderr and exits with error code """
    print(f"{argv[0]}: {message}", file=stderr)
    exit(84)

# ----------------------------------- Maths ---------------------------------- #


def arithmetic_mean(a, n, value):
    """ Compute the arithmetic mean  """
    res = 0
    try:
        res = (a * (n - 1) + value) / n
    except ZeroDivisionError:
        error("division by zero")
    return res


def RMSD(countries, op, n):
    """ Compute the RMSD from the arithmetic mean """
    res = 0

    try:
        res = sum_fct(
            countries,
            lambda l, i: get_y(l, i),
            lambda x, y: (x - y) ** 2,
            lambda l, i: op(l, i)
        )
        res = sqrt(res / n)
    except Exception as err:
        error(err)
    return res


def get_year(my_list, index):
    """ Returns the year value of a given index """
    return int(list(my_list[0].items())[index + 2][0])


def get_value(my_list, index):
    """ Returns the year value of a given index """
    return int(list(my_list[0].items())[index + 2][1])

# sqrt (sum( (Y - Ybis) **2) / N)

# avec:
# - Y    : data du fichier csv
# - Ybis : data calculé avec la droite de regression


def sum_fct(my_list, x, op = (lambda x, y: x), y = (lambda x, y: 1)):
    """ Sums all the values of a function """
    res = 0

    for i in range(len(my_list[0]) - 2):
        res += op(x(my_list, i), y(my_list, i))
    return res


def get_x(my_list, index):
    """ Returns the x value of a given index """
    res = 0
    try :
        for sublist in my_list:
            # print(f"key: {list(sublist.items())[index + 2]}")
            res += int(list(sublist.items())[index + 2][0])
    except Exception as err:
        error("invalid key present the database")
    return res


def get_y(my_list, index):
    """ Returns the y value of a given index """
    res = 0.0

    try:
        for sublist in my_list:
        # print(f"value: {list(sublist.items())[index + 2]}")
            res += int(list(sublist.items())[index + 2][1]) / 1_000_000
    except Exception as err:
        error("invalid value present the database")
    return res