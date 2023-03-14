##
## EPITECH PROJECT, 2022
## 205IQ
## File description:
## param_handling
##

from sys import argv
from utils import error

# ----------------------------------- Misc ----------------------------------- #

# too large IQ1: 398659

def check_params(params):
    if params[0] <= 0 or params[1] <= 0:
        error("values can't be negative or null")
    if params[0] > 200:
        error("Mean can't be superior to 200")
    if len(params) > 3:
        if params[2] < 0  or params[3] <= 0:
            error("min IQ can't be negative and max IQ can't be null")
        if params[2] > 200 or params[3] > 200:
            error("IQ min and max can't be superior to 200")
        if params[2] > params[3]:
            error("min IQ can't be higher than max IQ")


def get_params():
    res = []

    try:
        res.append(int(argv[1]))
        res.append(int(argv[2]))
        if len(argv) > 4:
            res.append(int(argv[3]))
            res.append(int(argv[4]))
        elif len(argv) > 3:
            res.append(0)
            res.append(int(argv[3]))
    except Exception as err:
        error(err)
    return res
