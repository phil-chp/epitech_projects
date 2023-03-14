##
## EPITECH PROJECT, 2021
## 108trigo (Workspace)
## File description:
## products
##

from handle_matrix import create_ide, create_empty_matrix
from my_math import fact, scalaire_product, matrix_product, sum_matrix, sub_matrix

def product_exp(x):
    ide = create_ide(x)
    res = create_empty_matrix(x)
    i = 0

    for i in range(100):
        temp = scalaire_product(ide, 1 / fact(i))
        for k in range(len(res)):
            for j in range(len(res[0])):
                res[k][j] += temp[k][j]
        ide = matrix_product(ide, x)
    return res

def product_cos(x):
    ide = create_ide(x)
    res = create_empty_matrix(x)
    i = 0
    k = 1
    for i in range(0, 100):
        if i != 0:
            ide = matrix_product(ide, x)
            ide = matrix_product(ide, x)
            k = ((-1)**i) / fact(2 * i)
        temp = scalaire_product(ide, k)
        for k in range(len(res)):
            for j in range(len(res[0])):
                res[k][j] += temp[k][j]
    return res

def product_sin(x):
    ide = create_ide(x)
    res = create_empty_matrix(x)
    k = 1
    ide = matrix_product(ide, x)
    for i in range(0, 100):
        if (i != 0):
            ide = matrix_product(ide, x)
            ide = matrix_product(ide, x)
            k = ((-1)**i) / fact(2 * i + 1)
        temp = scalaire_product(ide, k)
        for k in range(len(res)):
            for j in range(len(res[0])):
                res[k][j] += temp[k][j]
    return res

def product_cosh(x):
    res = product_exp(x)
    x = scalaire_product(x, -1)
    res2 = product_exp(x)
    res = scalaire_product(res, 1/2);
    res2 = scalaire_product(res2, 1/2);
    res = sum_matrix(res, res2)
    return res

def product_sinh(x):
    res = product_exp(x)
    x = scalaire_product(x, -1)
    res2 = product_exp(x)
    res = scalaire_product(res, 1/2)
    res2 = scalaire_product(res2, 1/2)
    res = sub_matrix(res, res2)
    return res

def get_funcs():
    funcs = {
        "EXP":  product_exp,
        "COS":  product_cos,
        "SIN":  product_sin,
        "COSH": product_cosh,
        "SINH": product_sinh,
    }
    return funcs
