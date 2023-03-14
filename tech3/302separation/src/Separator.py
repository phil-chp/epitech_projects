##
## EPITECH PROJECT, 2022
## 302separation (Workspace)
## File description:
## Sort
##

import re
from src.utils import error, print_matrix

MATRIX_MODE = 0
LENGTH_MODE = 1

PATH_LIM = 1000

class Separator:
    def __init__(self, datas, args):
        self.mode = MATRIX_MODE if len(args) == 1 else LENGTH_MODE

        try:
            self.max = -1      if self.mode == LENGTH_MODE else int(args[0])
            self.p1  = args[0] if self.mode == LENGTH_MODE else ""
            self.p2  = args[1] if self.mode == LENGTH_MODE else ""
        except ValueError:
            error("Invalid argument.")

        self.messages = datas
        self.pairs = []
        self.graph = {}

    # *--- Public ------------------------------------------------------------ #

    def run(self):
        self._getPairs()
        self._createGraph()

        if self.mode == LENGTH_MODE:
            self._handleLength()
        elif self.mode == MATRIX_MODE:
            self._handleMatrix()
        else:
            error("Bad arguments. (never reached)")

    # *--- Private ----------------------------------------------------------- #

    def _handleLength(self):
        people = sorted(self.graph.keys())
        matrix = []
        length = -1

        try:
            for x in range(len(people)):
                matrix.append([])
                for y in range(len(people)):
                    n = 1 if people[x] != people[y] and people[y] in self.graph[people[x]] else 0
                    matrix[x].append(n)
            self._royWarshall(matrix, PATH_LIM)
            length = matrix[people.index(self.p1)][people.index(self.p2)]
        except ValueError:
            pass
        if length == PATH_LIM:
            length = -1
        print(f"Degree of separation between {self.p1} and {self.p2}: {length}")


    def _handleMatrix(self):
        people = sorted(self.graph.keys())
        matrix = []

        print(*people, sep="\n", end="\n\n")
        for x in range(len(people)):
            matrix.append([])
            for y in range(len(people)):
                n = 1 if people[x] != people[y] and people[y] in self.graph[people[x]] else 0
                matrix[x].append(n)
        print_matrix(matrix, end="\n")
        self._royWarshall(matrix, self.max)
        print_matrix(matrix)


    def _royWarshall(self, matrix, max):
        for x in range(len(matrix)):
            for y in range(len(matrix)):
                if matrix[x][y] > 0:
                    matrix[x][y] = 1
                else:
                    matrix[x][y] = PATH_LIM
            matrix[x][x] = 0

        for z in range(len(matrix)):
            for x in range(len(matrix)):
                for y in range(len(matrix)):
                    matrix[x][y] = min(matrix[x][y], matrix[x][z] + matrix[z][y])

        for x in range(len(matrix)):
            for y in range(len(matrix)):
                if matrix[x][y] > max:
                    matrix[x][y] = 0


    def _getPairs(self):
        regex1 = re.compile(r" is friends with ")
        message = re.sub(regex1, "  ", self.messages)
        message = message.split('\n')
        for line in message:
            if len(line) > 0:
                self.pairs.append(line.split("  "))


    def _createGraph(self):
        for _, (p1, p2) in enumerate(self.pairs):
            self._buildGraphLinks(p1, p2);
            self._buildGraphLinks(p2, p1);


    def _buildGraphLinks(self, person, friend):
        if person not in self.graph.keys():
            self.graph[person] = []
        self.graph[person].append(friend) if friend not in self.graph[person] else self.graph[person]
