##
## EPITECH PROJECT, 2021
## 108trigo (Workspace)
## File description:
## my_math
##

from sys import exit, stderr
from copy import deepcopy

def fact(n):
    res = 1

    if n == 0 or n == 1:
        return 1
    while (n > 1):
        res *= n
        n -= 1
    return res

def exp(x):
    res = 0
    i = 0

    while (i < 100):
        res += x ** i / fact(i)
        i += 1
    return res

def cosh(x):
    return (exp(x) + exp(-x) / 2)

def sinh(x):
    return (exp(x) - exp(-x) / 2)

def msin(x):
    res = 0
    i = 0

    while (i < 100):
        res += (-1) ** i * (x ** (2* i + 1) / fact(2 * i + 1))
        i += 1
    return res

def mcos(x):
    res = 0
    i = 0

    while (i < 100):
        res += (-1) ** i * (x ** (2 * i) / fact(2 * i))
        i += 1
    return res

def scalaire_product(ide, f):
    temp = deepcopy(ide)

    for i in range(len(temp)):
        for j in range(len(temp[0])):
            temp[i][j] *= f
    return temp

def matrix_product(A, B):
    res = []
    temp = []
    k = 0
    i = 0

    if len(A[0]) != len(B):
        print("ValueError: matrices are not aligned\n", file=stderr)
        exit(84)
    for i in range(len(A)):
        j = 0
        temp = []
        for j in range(len(B[0])):
            element = 0
            k = 0
            for k in range(len(A[0])):
                element += float(A[i][k]) * float(B[k][j])
            temp.append(element)
        res.append(temp)
    return res

def sum_matrix(A, B):
    for i in range(len(A)):
        for j in range(len(A[0])):
            A[i][j] += B[i][j]
    return A

def sub_matrix(A, B):
    for i in range(len(A)):
        for j in range(len(A[0])):
            A[i][j] -= B[i][j]
    return A
