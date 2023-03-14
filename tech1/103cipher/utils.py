#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## 103cipher
## File description:
## main
##

from sys import exit, argv
from extra_utils import error_handling, mat_key, encoder_key_mat, calc_row

def calc_col(m):
    for j in range(len(m[0])):
        j += 1
    return j

def mult_matrix(a, b):
    i = calc_col(a)
    j = calc_row(b)

    if i == j:
        stock = i
        i = calc_row(a)
        j = calc_col(b)
        m = [[0 for x in range(j)] for y in range(i)]
    else:
        error_handling(84)
    for k in range(len(m)):
        for n in range(len(m[k])):
            for count in range(stock):
                m[k][n] += a[k][count] * b[count][n]
    return m

def generator_mat_text(i, text):
    temp = int((len(text) / i) + (len(text) % i))
    m = [[0 for x in range(i)] for y in range(temp)]
    return m

def encode_text(text, m):
    s = 0
    i = calc_row(m)
    n = generator_mat_text(i, text)
    for i in range(len(n)):
        for j in range(len(n[i])):
            if s < len(text):
                n[i][j] = ord(text[s])
            else:
                n[i][j] = 0
            s += 1
    return n

def show_matrix_encode(matrix):
    for i in range(len(matrix)):
        string = ''
        for j in range(len(matrix[i])):
            string += ("%-*d" % (8, matrix[i][j]))
        print(string.rstrip())
    return
