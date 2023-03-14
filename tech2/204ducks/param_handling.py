##
## EPITECH PROJECT, 2022
## 203hotline
## File description:
## 203hotline
##

from sys import argv, exit

from utils import error


def check_params(params):
    if params <= 0:
        error("first argument cannot be null or lower")
    # if params > 4.295:
    #     error("math domain error")
    # if paramas > 4.295 t['1'] < 0 --> maths error ?

def get_params():
    try:
        res = float(argv[1])
    except Exception as err:
        error(err)
    return (res)