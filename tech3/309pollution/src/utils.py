##
## EPITECH PROJECT, 2022
## 307multigrains
## File description:
## utils
##

from sys import argv, stderr
from math import floor, ceil
import argparse

PRINT_USAGE      = True
DONT_PRINT_USAGE = False

def usage(ret = 0):
    print("USAGE")
    print("\t./309pollution n file x y")
    print("DESCRIPTION")
    print("\tn\tnumber of points on the grid axis")
    print("\tfile\tcsv file containing the data points x;y;p")
    print("\tx\tabscissa of the point whose pollution level we want to know")
    print("\ty\tordinate of the point whose pollution level we want to know")
    exit(ret)


def error(msg, print_usage=DONT_PRINT_USAGE):
    """ Given an error message, prints it   """
    """ to stderr and exits with error code """
    print(f"{argv[0]}: {msg}", file=stderr)
    if print_usage:
        print()
        usage(84)
    else:
        exit(84)

# ============================================================================ #

# def print_table(table):
#     for x in range(len(table)):
#         l = len(table[x]) - 1
#         for y in range(len(table[x])):
#             print(table[x][y], end='\t' if y != l else '')
#         print()


# def get_file_content(file):
#     """ Given a file, returns its content as a string """
#     try:
#         with open(file, "r") as f:
#             contents = f.read()
#     except FileNotFoundError:
#         error("File not found.")
#     return contents


def check_positive(value):
    ivalue = int(value)
    if ivalue <= 0:
        raise argparse.ArgumentTypeError("%s is an invalid positive int value" % value)
    return ivalue


def parse_args():
    parser = argparse.ArgumentParser(description='Calculate pollution level at a point using bezier curves', usage=argparse.SUPPRESS)
    parser.add_argument('n',    metavar='n',    type=check_positive,            help=' number of points on the grid axis')
    parser.add_argument('file', metavar='file', type=argparse.FileType('r'),    help='csv file containing the data points x;y;p')
    parser.add_argument('pos' , metavar='x y',  type=float, nargs=2, help='coordinates of the point whose pollution level we want to know')

    try:
        args = parser.parse_args()
    except:
        usage(84)
    return args


# def rotate(l, n):
#     return l[n:] + l[:n]


# def round2(value, decimals=0):
#     value *= 10 ** decimals
#     rounded_value = floor(value) if value - floor(value) < 0.5 else ceil(value)
#     return rounded_value / 10 ** decimals
