##
## EPITECH PROJECT, 2022
## 306radiator
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
    print("\t./306radiator n ir jr [i j]")
    print("DESCRIPTION")
    print("\tn\tsize of the room")
    print("\t(ir, jr)\tcoordinates of the radiator")
    print("\t(i, j)\tcoordinates of a point in a room")
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

def print_table(table):
    for x in range(len(table)):
        l = len(table[x]) - 1
        for y in range(len(table[x])):
            print(table[x][y], end='\t' if y != l else '')
        print()

def check_positive(value):
    ivalue = int(value)
    if ivalue <= 0:
        raise argparse.ArgumentTypeError("%s is an invalid positive int value" % value)
    return ivalue

def parse_args():
    parser = argparse.ArgumentParser(description='Calculates heat repartition in a room')
    parser.add_argument('size', metavar='n'     , type=check_positive,            help='size of the room')
    parser.add_argument('rpos', metavar='ir, jr', type=check_positive, nargs=2  , help='coordinates of the radiator')
    parser.add_argument('pos' , metavar='(i, j)', type=check_positive, nargs='*', help='coordinates of a point in a room')
    try:
        args = parser.parse_args()
    except:
        usage(84)
    if args.size < 3:
        exit(84)
    if len(args.pos) != 0 and len(args.pos) != 2:
        error("Invalid number of arguments.")
    elif len(args.pos) == 2:
        if args.pos[0] < args.size - 1 or args.pos[1] < args.size - 1:
            exit(84)
    return args


def rotate(l, n):
    return l[n:] + l[:n]


def round2(value, decimals=0):
    value *= 10 ** decimals
    rounded_value = floor(value) if value - floor(value) < 0.5 else ceil(value)
    return rounded_value / 10 ** decimals
