##
## EPITECH PROJECT, 2022
## 303make (Workspace)
## File description:
## utils
##

from sys import argv, stderr

def usage():
    print("USAGE")
    print("\t./303make makefile [file]")
    print("DESCRIPTION")
    print("\tmakefile\tname of the makefile")
    print("\tfile\tname of the recently modified file")
    exit(0)


def error(msg):
    """ Given an error message, prints it   """
    """ to stderr and exits with error code """
    print(f"{argv[0]}: {msg}", file=stderr)
    exit(84)

# ============================================================================ #


def argument_parsing(args):
    if len(args) < 2:
        error("Invalid number of arguments.")
    if args[1] == "-h":
        usage()
    return args[1:]


def print_table(table):
    for line in table:
        print("[", end = '')
        for i in range(len(line)):
            if (i == len(line) - 1):
                print(f"{line[i]}]")
            else:
                print(line[i], end = ' ')


def get_file_content(file):
    """ Given a file, returns its content as a string """
    contents = ""
    try:
        with open(file, "r") as f:
            contents = f.read()
    except FileNotFoundError:
        error("File not found.")
    return contents
