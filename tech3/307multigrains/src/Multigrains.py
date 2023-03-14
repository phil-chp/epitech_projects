##
## EPITECH PROJECT, 2023
## 307multigrains (Workspace)
## File description:
## Multigrains
##

from src.Matrix import Matrix

GRAINS_PER_TON = {
    #          F1 F2 F3 F4
    'oat':    [ 1, 1, 2, 0 ],
    'wheat':  [ 0, 2, 1, 0 ],
    'corn':   [ 1, 0, 0, 3 ],
    'barley': [ 0, 1, 1, 1 ],
    'soy':    [ 2, 0, 0, 2 ]
}

class Multigrains:
    def __init__(self, data):
        self.tons = data.tons
        self.grains = {}
        for n, (key, _) in enumerate(GRAINS_PER_TON.items()):
            self.grains[key] = {}
            self.grains[key]['price'] = data.prices[n]

        self.matrix = Matrix.get_matrix(data, GRAINS_PER_TON)

    # -------------------------------- Public -------------------------------- #

    def run(self):
        """ Run the logic """
        order = [-1, -1, -1, -1]
        res   = [0 , 0 , 0 , 0, 0]
        i = 0

        while 1:
            i += 1
            if i == 6:
                break
            x, y = self._find_pivot()
            if (x < 0 or y < 0):
                break
            self._pivot(x, y)
            order[y] = x
        for i in range (0, 4):
            if order[i] != -1:
                res[order[i]] = self.matrix[i][len(self.matrix[i]) - 1]

        self.show(res)


    def show(self, res):
        """ Show the results """
        ressources = [f"{self.tons[n]} F{n + 1}" for n in range(len(self.tons))]
        print(f"Ressources: {', '.join(ressources)}\n")

        for i, (key, value) in enumerate(self.grains.items()):
            print(f"{key.capitalize()}: {res[i]} units at ${value.get('price')}/unit")

        print(f"\nTotal production value: ${self.matrix[-1][-1]:.2f}")

    # -------------------------------- Private ------------------------------- #


    def _find_pivot(self):
        """" Find the pivot """
        if (len(self.matrix) <= 0 or len(self.matrix[0]) <= 5):
            return (-1, -1)
        lenY = len(self.matrix)
        lenX = len(self.matrix[0])
        line = self.matrix[- 1]
        copy = line[0:5]
        min_val = min(copy)
        if min_val >= 0:
            return (-1, -1)
        x = copy.index(min_val)
        y = -1
        min_val = 999_999
        for i in range(0, lenY - 1):
            if (self.matrix[i][lenX - 1]):
                if (self.matrix[i][x] > 0 and (min_val > self.matrix[i][lenX - 1] / self.matrix[i][x] and self.matrix[i][lenX - 1] / self.matrix[i][x] > 0)):
                    y = i
                    min_val = self.matrix[i][lenX - 1] / self.matrix[i][x]
            elif min_val > self.matrix[i][x] and self.matrix[i][x] > 0:
                y = i
                min_val = self.matrix[i][lenX - 1] / self.matrix[i][x]
        return (x, y)

    def _pivot(self, x, y):
        """ Pivot the matrix """
        p = self.matrix[y][x]
        for a in range(len(self.matrix[y])):
            self.matrix[y][a] = self.matrix[y][a] / p
        maxY, maxX = len(self.matrix), len(self.matrix[0])
        for i in range(maxY):
            if i == y:
                continue
            val = self.matrix[i][x]
            for j in range(maxX):
                self.matrix[i][j] -= val * self.matrix[y][j]
