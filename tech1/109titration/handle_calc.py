##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## handle_calc.py
##

from sys import stderr
from utils import catch_error

def calc_derivate(arr, i, p):
    n = int(1 / p)
    t_a = arr[i + n][0] - arr[i][0]
    t_b = arr[i][0] - arr[i - n][0]
    try:
        t_af = (arr[i + 1][1] - arr[i][1]) / t_a
        t_be = (arr[i][1] - arr[i - 1][1]) / t_b
    except Exception as e:
        catch_error(e)
    if (t_a + t_b == 0):
        exit(84)
    return [arr[i][0], (t_a * t_be + t_b * t_af) / (t_a + t_b)]

def calc_eq(data, my_derivate, opt):
    result = [1, 0]
    default = 0

    for i in range(1, len(my_derivate) - 1):
        if default < my_derivate[i][1]:
            default = my_derivate[i][1]
            result[0] = data[i][0]
            result[1] = i
    if (opt == 1):
        print("\nEquivalence point at %.1f ml" % (result[0]))
    return 0

def derivate(arr):
    arr_derivate = [[0, 0]]

    for i in range(1, len(arr) - 1):
        arr_derivate.append(calc_derivate(arr, i, 1))
        print("%.1f ml -> %.2f" % (arr[i][0], arr_derivate[i][1]))
    calc_eq(arr, arr_derivate, 1)
    return arr_derivate

def second_derivate(arr_deriv):
    arr_derivate_sec = [[0, 0],[0, 0]]

    for i in range(2, len(arr_deriv) - 1):
        arr_derivate_sec.append(calc_derivate(arr_deriv, i, 1))
        print("%.1f ml -> %.2f" % (arr_derivate_sec[i][0], arr_derivate_sec[i][1]))
    calc_eq(arr_deriv, arr_derivate_sec, 0)
    return arr_derivate_sec

def arr_first_derivative(derive):
    arr = []
    maxi = derive[0][1]

    for i in range(len(derive)):
        if derive[i][1] > maxi:
            maxi = derive[i][1]
            arr = []
            arr.append([derive[i - 1][0], derive[i - 1][1]])
            arr.append([derive[i][0], derive[i][1]])
            arr.append([derive[i + 1][0], derive[i + 1][1]])
    return arr

def arr_second_derivative(sec_deriv, arr_fderiv):
    arr = []
    i = 0

    for i in range(len(sec_deriv)):
        if sec_deriv[i][0] == arr_fderiv[0][0]:
            break;
    arr.append([sec_deriv[i][0], sec_deriv[i][1]])
    arr.append([sec_deriv[i + 1][0], sec_deriv[i + 1][1]])
    arr.append([sec_deriv[i + 2][0], sec_deriv[i + 2][1]])
    return arr

def get_intercept(arr_fderiv, arr_sderiv):
    b = []

    for i in range(3):
        b.append(arr_sderiv[i][1] - arr_fderiv[i][1] * arr_fderiv[i][0])
    return b

def second_derivate_estimate(arr_deriv, arr_sec):
    arr_fderiv = arr_first_derivative(arr_deriv)
    arr_sderiv = arr_second_derivative(arr_sec, arr_fderiv)
    ml = arr_fderiv[0][0]
    a = arr_fderiv[0][1]
    arr = []
    i = 0

    while (ml <= arr_fderiv[2][0]):
        try:
            if (ml < arr_fderiv[1][0]):
                a = (arr_sderiv[1][1] - arr_sderiv[0][1]) / (arr_sderiv[1][0] - arr_sderiv[0][0])
                b =  arr_sderiv[0][1] - a * arr_sderiv[0][0]
            else:
                a = (arr_sderiv[2][1] - arr_sderiv[1][1]) / (arr_sderiv[2][0] - arr_sderiv[1][0])
                b =  arr_sderiv[2][1] - a * arr_sderiv[2][0]
        except Exception as e:
            catch_error(e)
        y = a * ml + b
        arr.append([ml, y])
        print("%.1f ml -> %.2f" % (arr[i][0], arr[i][1]))
        ml += 0.1
        i += 1
    calc_eq(arr, arr_deriv, 1)
    return 0
