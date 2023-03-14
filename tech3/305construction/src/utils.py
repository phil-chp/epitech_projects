##
## EPITECH PROJECT, 2022
## 304pacman (Workspace)
## File description:
## utils
##

from sys import argv, stderr

PRINT_USAGE      = True
DONT_PRINT_USAGE = False

def usage(ret = 0):
    print("USAGE")
    print("\t./305construction file")
    print("DESCRIPTION")
    print("\tfile file describing the tasks")
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


def argument_parsing(args):
    if len(args) == 2 and args[1] == "-h":
        usage()
    elif len(args) != 2:
        error("Invalid number of arguments.", PRINT_USAGE)
    return args[1]


def get_file_content(file):
    """ Given a file, returns its content as a string """
    try:
        with open(file, "r") as f:
            contents = f.read()
    except FileNotFoundError:
        error("File not found.")
    return contents


def print_table(table):
    for x in range(len(table)):
        for i in range(len(table[x])):
            print(table[x][i], end=(' ' if i == len(table[x]) - 1 else ''))
        print()
