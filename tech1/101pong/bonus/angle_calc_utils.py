#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## defs
## File description:
## Second part of 101pong
##

from sys import argv, exit
from math import pi


def security(n):
    if (len(argv) != 8):
        print("Error : wrong amount of arguments")
        print("How to use : ./101pong x0 y0 z0 x1 y1 z1 time")
        exit(84)
    if (n < 0):
        print("Error : time value cannot be negative")
        print("How to use : ./101pong x0 y0 z0 x1 y1 z1 time")
        exit(84)
    return


def define_points():
    try:
        a = [int(float(argv[1])), int(float(argv[2])), int(float(argv[3]))]
        b = [int(float(argv[4])), int(float(argv[5])), int(float(argv[6]))]
        n = int(argv[7])

    except:
        if (isinstance(argv[7], int) == False):
            print("Error : time value has to be int")
        else:
            print("Error : bad parameters")
        print("How to use : ./101pong x0 y0 z0 x1 y1 z1 time")
        exit(84)
    return a, b, n


def vect(a, b):
    vect_ab = []
    for i in range(3):
        vect_ab.append(b[i] - a[i])
        i += 1
    return vect_ab


def define_inter(a, b, vect_ab):
    if (b[2] == 0) and (a[2] != 0):
        inter = b
    elif (b[2] == a[2]):
        inter = pi
    else:
        j = -(a[2] / vect_ab[2])
        inter = (vect_ab[0] * j + a[0], vect_ab[1] * j + a[1], vect_ab[2] * j + a[2])
    return inter


def define_time(a, vect_ab, n):
    n_time_vect = []
    for i in range(3):
        n_time_vect.append(vect_ab[i] * (n + 1) + a[i])
        i += 1
    return n_time_vect
