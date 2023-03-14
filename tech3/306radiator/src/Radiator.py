##
## EPITECH PROJECT, 2022
## 306radiator
## File description:
## Radiator
##

from src.utils import print_table, rotate, round2
from src.Gauss import Gauss

X_EQUALS_Y  = lambda x, y, _: 1 if x == y else 0
TEMPERATURE = lambda x, y, n: 4 if abs(y - x) in {1, n} else (-16 if y == x else 0)

class Radiator:
    def __init__(self, datas):
        self.n = datas.size
        self.n_max = self.n ** 2

        self.rpos = {'x': datas.rpos[0], 'y': datas.rpos[1]}
        self.pos = datas.pos # if len(datas.pos > 0) else [0, 0]

        self.A = [[0 for _ in range(self.n_max)] for _ in range(self.n_max)]
        self.Y = []
        self.X = []


    # -------------------------------- Public -------------------------------- #

    def run(self):
        self.generate_A()
        self.generate_Y()
        # self.generate_X()
        self.X = self.Y # TODO: remove, just for testing
        self.show()


    def show(self):
        print_table(self.A)
        print()
        [print(round2(f)) for f in self.X]


    def generate_A(self):
        funcs = [TEMPERATURE, X_EQUALS_Y]
        max   = self.n_max - (self.n + 1)
        off   = [self.n - 2, 2]
        pos   = self._fill_block(0, self.n + 1, X_EQUALS_Y)

        while pos < max:
            pos = self._fill_block(pos, pos + off[0], funcs[0])
            off = rotate(off, 1)
            funcs = rotate(funcs, 1)
        self._fill_block(pos, pos + self.n + 1, X_EQUALS_Y)


    def generate_Y(self):
        place = self.n * self.rpos['x'] + self.rpos['y']
        if place >= self.n_max:
            exit(84)
        for i in range(self.n_max):
            self.Y.append(-300 if i == place else 0)


    def generate_X(self):
        Gauss.get_gaussian_pivot(self.n, self.A, self.Y)
        pass

    # ------------------------------- Private -------------------------------- #

    def _fill_block(self, min, max, func):
        for x in range(min, max):
            for y in range(self.n_max):
                self.A[x][y] = func(x, y, self.n)
        return max
