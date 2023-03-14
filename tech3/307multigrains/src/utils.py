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
    print("\t./307multigrains n1 n2 n3 n4 po pw pc pb ps")
    print("DESCRIPTION")
    print("\tn1\tnumber of tons of fertilizer F1")
    print("\tn2\tnumber of tons of fertilizer F2")
    print("\tn3\tnumber of tons of fertilizer F3")
    print("\tn4\tnumber of tons of fertilizer F4")
    print("\tpo\tprice of one unit of oat")
    print("\tpw\tprice of one unit of wheat")
    print("\tpc\tprice of one unit of corn")
    print("\tpb\tprice of one unit of barley")
    print("\tps\tprice of one unit of soy")
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
    parser = argparse.ArgumentParser(description='Statistics for farmers', usage=argparse.SUPPRESS)
    parser.add_argument('tons', metavar='n1 n2 n3 n4', type=int, nargs=4, help='number of tons of fertilizer')
    parser.add_argument('prices', metavar='po pw pc pb ps', type=check_positive, nargs=5, help='price of one unit of grain')

    try:
        args = parser.parse_args()
    except:
        usage(84)
    for t in args.tons:
        if t < 0:
            error("Tons cannot be negative.")
    for t in args.prices:
        if t < 0:
            error("Prices cannot be negative.")
    # elif len(args.pos) == 2:
    #     if args.pos[0] < args.size - 1 or args.pos[1] < args.size - 1:
    #         exit(84)
    return args


# def rotate(l, n):
#     return l[n:] + l[:n]


# def round2(value, decimals=0):
#     value *= 10 ** decimals
#     rounded_value = floor(value) if value - floor(value) < 0.5 else ceil(value)
#     return rounded_value / 10 ** decimals
