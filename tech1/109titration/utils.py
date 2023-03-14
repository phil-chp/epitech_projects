##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## utils.py
##

from sys import argv, exit
from os import stat

def usage(opt):
    print("USAGE:")
    print("\t./109titration file\n")
    print("DESCRIPTION:")
    print("\tfile\t a csv file containing \"vol;ph\" lines")
    exit(opt)

def catch_error(e):
    print("109titration: %s" % (e))
    exit(84)

def get_argument():
    arr = []
    if len(argv) != 2:
        exit(84)
    if argv[1] == "-h":
        usage(0)
    try:
        if stat(argv[1]).st_size < 3:
            exit(84)
        f = open(argv[1], "r")
        for line in f:
            splitter = line.split(';')
            if (len(splitter) != 2):
                exit(84)
            splitter[0] = float(splitter[0])
            splitter[1] = float(splitter[1])
            arr.append(splitter)
    except Exception as e:
        catch_error(e)
    return arr
