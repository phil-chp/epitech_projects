#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## defs
## File description:
## Second part of 101pong
##

from sys import argv, exit
from math import pi

def security():
    if (len(argv) != 8):
        print("Not enough args")
        exit(84)
    return

def definePoints():
    try:
        A = [float(argv[1]), float(argv[2]), float(argv[3])]
        B = [float(argv[4]), float(argv[5]), float(argv[6])]
        n = float(argv[7])
    except:
        print("bad parameters")
        exit(84)
    return A, B, n

def vect(A, B):
    vectAB = []
    for i in range(3):
        vectAB.append(B[i] - A[i])
        i += 1
    return vectAB

def defineInter(A, B, vectAB):
    if (B[2] == 0 and A[2] != 0):
        inter = B
    elif (B[2] == A[2]):
        inter = pi
    else:
        j = -(A[2] / vectAB[2])
        inter = (vectAB[0] * j + A[0], vectAB[1] * j + A[1], vectAB[2] * j + A[2])
    return inter

def defineTime(A, vectAB, n):
    nTimeVect = []
    for i in range(3):
        nTimeVect.append(vectAB[i] * (n + 1) + A[i])
        i += 1
    return nTimeVect