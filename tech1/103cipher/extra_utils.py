#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## 103cipher
## File description:
## main
##

from sys import exit, argv

def error_handling(n):
    if n == 84 or len(argv) != 4:
        print("Usage: ./103cipher [message] [key] [code]")
        print("       The key must be less or equal than 16 characters.")
        print("       The code must be either 0 or 1.")
        exit(84)
    return

def mat_key(key):
    key_len = len(key)
    if key_len == 1:
        i = 1
    elif key_len <= 4:
        i = 2
    elif key_len <= 9:
        i = 3
    elif key_len <= 16:
        i = 4
    m = [[0 for x in range(i)] for y in range(i)]
    return m

def encoder_key_mat(m, key):
    s = 0
    for i in range(len(m)):
        for j in range(len(m[i])):
            if s < len(key):
                m[i][j] = ord(key[s])
            else:
                m[i][j] = 0
            s += 1
    return m

def calc_row(m):
    for i in range(len(m)):
        i += 1
    return i
