##
## EPITECH PROJECT, 2022
## 306radiator (Workspace)
## File description:
## Gauss
##

import copy

#* All the methods used here come from this article:
#* http://desaintar.free.fr/python/cours/pivot.pdf

class Gauss:
    # -------------------------------- Public -------------------------------- #

    @staticmethod
    def get_gaussian_pivot(n, A0, b0):
        """ Renvoie la solution X du système de Cramer A0 X = b0 """
        A = copy.deepcopy(A0)
        b = copy.deepcopy(b0)

        A = [[float(x) for x in y] for y in A]

        for j in range(n - 1):
            i0 = Gauss._partial_pivot(A, j)
            Gauss._swap_line(A, j, i0)
            Gauss._swap_line(b, j, i0)
            for i in range(j + 1, n):
                x = A[i][j] / A[j][j]
                Gauss._transvect(A, i, j, -x, n)
                Gauss._transvect(b, i, j, -x, n)
        return Gauss._triangulate(A, b)

    # -------------------------------- Private ------------------------------- #
    @staticmethod
    def _triangulate(A, b):
        """ Renvoie la solution du système Ax = b
            lorsque A est tringulaire supérieure inversible """
        n = len(b)
        x = [0 for _ in range(n)]
        x[n - 1] = b[n - 1] / A[n - 1][n - 1]

        for i in range(n - 2, -1, -1):
            s = 0
            for j in range(i + 1,n):
                s = s + A[i][j] * x[j]
                x[i] = (b[i] - s) / A[i][i]
        return x

    @staticmethod
    def _transvect(A, i, j, mu, n):
        """Applique l'opération élémentaire Li <- Li + mu * Lj à la matrice A """
        if type(A[0]) != list:
            A[i] = A[i] + mu * A[j]
        else:
            n = len(A[0])
        for k in range(n):

            print(f"mu:{mu}")
            print(f"A[j][k]:{A[j][k]}")
            # print(f"i:{i}, j:{j}, k:{k}, mu:{mu}, A[i][k]:{A[i][k]}, A[j][k]:{A[j][k]}")
            print("A[i][k] + mu * A[j][k]: ", mu * A[j][k])
            print("A[i][k] + mu * A[j][k]: ", A[i][k] + mu * A[j][k])
            # A[i][k] = A[i][k] + mu * A[j][k]

    @staticmethod
    def _swap_line(A, i, j):
        """Applique l'opération élémentaire Li <-> Lj à la matrice A"""
        temp = A[i]
        A[i] = A[j]
        A[j] = temp

    @staticmethod
    def _partial_pivot(A, j0):
        n = len(A)
        imax = j0
        for i in range(j0 + 1, n):
            if abs(A[i][j0]) > abs(A[imax][j0]):
                imax = i
        return imax

    # -------------------------------- Private ------------------------------- #
