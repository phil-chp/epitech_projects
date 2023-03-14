##
## EPITECH PROJECT, 2022
## 203hotline
## File description:
## 203hotline
##

from sys import argv, exit

from utils import error


def check_params(params):
    if params[0] <= 0:
        error("first argument cannot be null or lower")
    if len(params) == 2 and params[0] < params[1]:
        error("first argument cannot be lower than the second one")


def get_params():
    res = []
    try:
        nb1 = int(argv[1])
        res.append(nb1)
        if (len(argv) == 3):
            nb2 = int(argv[2])
            res.append(nb2)
    except Exception as err:
        error(err)
    return (res)