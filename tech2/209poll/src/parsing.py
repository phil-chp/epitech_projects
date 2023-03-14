##
## EPITECH PROJECT, 2022
## 206neutrinos (Workspace)
## File description:
## parsing
##

from src.utils import usage, error
import csv

# ----------------------------------- Misc ----------------------------------- #

def get_params(args):
    res = []
    if len(args) == 2 and args[1] == '-h':
        usage()
    if (len(args) !=4 ):
        error("Invalid number of arguments")
    try:
        for arg in args[1:-1]:
            res.append(int(arg))
        res.append(float(args[-1]))
    except Exception as err:
        error(err)
    return res

def check_args(args):
    if args[0] < args[1] or args[2] > 100:
        error("Wrong args.")
    if args[0] <= 0 or args[1] <= 0 or args[2] <= 0:
        error("Wrong args.")