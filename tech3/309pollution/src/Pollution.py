##
## EPITECH PROJECT, 2023
## 309pollution
## File description:
## Pollution
##

from math import factorial, pow

class Pollution:
    def __init__(self, args):
        self.n = args.n - 1
        self.x = args.pos[0] / self.n
        self.y = args.pos[1] / self.n
        self.file = []
        for i in range(self.n + 1):
            self.file.append([])
            for j in range(self.n + 1):
                self.file[i].append(0.0)
        for i in args.file:
            self.file[int(i.split(';')[0])][int(i.split(';')[1])] = float(i.split(';')[2])
        self.result = 0

    # -------------------------------- Public -------------------------------- #

    def run(self):
        self._calc_boor_coox()
        print("%.2f" % self.result)

    # -------------------------------- Private ------------------------------- #

    def _calc_boor_coox(self):
        for i in range(self.n + 1):
            for j in range(self.n + 1):
                bernX = self._calc_bernstein(self.n, i, self.x)
                bernY = self._calc_bernstein(self.n, j, self.y)
                self.result += bernX * bernY * self.file[i][j]

    def _calc_bernstein(self, n, i, u):
        a = self._calc_coeff(n, i)
        b = pow(u, i)
        c = pow(1 - u, n - i)
        return a * b * c

    def _calc_coeff(self, n, i):
        return factorial(n) / (factorial(i) * factorial(n - i))
