##
## EPITECH PROJECT, 2022
## 302separation (Workspace)
## File description:
## utils
##

from sys import argv, stderr

def usage(code = 84):
    print("USAGE")
    print("\t./302separation file [n | p1 p2]")
    print("DESCRIPTION")
    print("\tfile\tfile that contains the list of facebook connexions")
    print("\tn\tmaximum length of the paths")
    print("\tpi\tname of someone in the file")
    exit(code)

def error(msg, print_usage=False):
    """ Given an error message, prints it   """
    """ to stderr and exits with error code """
    print(f"{argv[0]}: {msg}", file=stderr)
    if print_usage:
        print("", file=stderr)
        usage()
    exit(84)

# ============================================================================ #

def get_file_content(file):
    """ Given a file, returns its content as a string """
    res = ""
    try:
        with open(file, "r") as f:
            res = f.read()
    except FileNotFoundError:
        error("File not found.")
    return res


def argument_parsing(args):
    if len(args) < 2:
        usage()
    if args[1] == "-h":
        usage()
    if len(args) != 3 and len(args) != 4:
        error("Invalid number of arguments.", True)
    try:
        if len(args) == 3 and int(args[2]) < 0:
            error("Invalid argument.")
    except ValueError:
        error("Invalid argument.")
    return args[1:]


def print_matrix(matrix, end=""):
    """ Given a matrix, prints it """
    for line in matrix:
        print(*line, sep=" ")
    print("", end=end)
