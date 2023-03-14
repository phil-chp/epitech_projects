##
## EPITECH PROJECT, 2021
## 108trigo (Workspace)
## File description:
## handle_matrix
##

from sys import argv
from copy import deepcopy

def error_handling(n):
    print("USAGE")
    print("\t./108trio fun a0 a1 a2 ...\n")
    print("DESCRIPTION")
    print("\tfun\tfunction to be applied, among at least \"EXP\", \"COS\", \"SIN\", \"COSH\" and \"SINH\"")
    print("\tai\tcoeficients of the matrix")
    exit(n)

def get_matrix_size(av):
    matrix_size = 0

    for i in range(10):
        if len(av) == i ** 2 + 2:
            matrix_size = i
    if matrix_size == 0:
        error_handling(84)
    return matrix_size

def get_matrix(matrix_size):
    temp = []
    x = []
    j = 0

    for i in range(2, len(argv)):
        if j < matrix_size:
            temp.append(int(argv[i]))
            j += 1
        else:
            x.append(temp)
            temp = []
            temp.append(int(argv[i]))
            j = 1
    x.append(temp)
    return x

def print_matrix(x):
    for i in range(len(x)):
        string = ''
        for j in range(len(x[i])):
            string += ("%.2f" % (x[i][j]))
            if (j != len(x[i]) - 1):
                string += ("\t")
        print(string.rstrip())
    return 0

def create_ide(A):
    res = deepcopy(A)

    for i in range(len(A)):
        for j in range(len(A[0])):
            if (i == j):
                res[i][j] = 1
            else:
                res[i][j] = 0
    return res

def create_empty_matrix(x):
    temp = []
    res = []

    for i in range(len(x)):
        temp = []
        for j in range(len(x[0])):
            temp.append(0)
        res.append(temp)
    return res
