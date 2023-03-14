##
## EPITECH PROJECT, 2022
## 304pacman (Workspace)
## File description:
## utils
##

from sys import argv, stderr

def usage(ret = 0):
    print("\tfile\tfile describing the board, using the following characters:")
    print("\t\t\t\t'0' for an empty square,")
    print("\t\t\t\t'1' for a wall,")
    print("\t\t\t\t'F' for the ghost's position,")
    print("\t\t\t\t'P' for Pacman's position.")
    print("\tc1\tcharacter to display for a wall")
    print("\tc2\tcharacter to display for an empty space.")
    exit(ret)


def error(msg):
    """ Given an error message, prints it   """
    """ to stderr and exits with error code """
    print(f"{argv[0]}: {msg}", file=stderr)
    exit(84)

# ============================================================================ #

def argument_parsing(args):
    if args[1] == "-h":
        usage()
    if len(args) < 4:
        error("Invalid number of arguments.")
    return args[1:]


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
