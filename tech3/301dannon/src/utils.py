##
## EPITECH PROJECT, 2022
## 301dannon (Workspace)
## File description:
## utils
##

from sys import argv, stderr

def usage():
    print("USAGE")
    print("\t./301dannon file")
    print("DESCRIPTION")
    print("\tfile file that contains the numbers to be sorted, separated by spaces")
    exit(0)

def error(msg):
    """ Given an error message, prints it   """
    """ to stderr and exits with error code """
    print(f"{argv[0]}: {msg}", file=stderr)
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
    if len(args) != 2:
        error("Invalid number of arguments.")
    if args[1] == "-h":
        usage()
    return args[1]
