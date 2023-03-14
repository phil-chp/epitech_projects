##
## EPITECH PROJECT, 2022
## 304pacman (Workspace)
## File description:
## Pacman
##

from src.utils import error, print_table
from src.Node import Node

class Pacman:
    def __init__(self, map, c1, c2):
        self.check_file(map)

        self.wall    = c1
        self.air     = c2

        self.in_map  = [list(line) for (_, line) in enumerate(list(filter(bool, map.split('\n'))))]
        self.out_map = [list(line.replace('1', self.wall).replace('0', self.air)) for (_, line) in enumerate(list(filter(bool, map.split('\n'))))]


        self.start   = {}
        self.end     = {}

    # -------------------------------- Public -------------------------------- #

    def run(self):
        self.find_nodes()
        self.traverse_map(self.start, 0)

    def display(self):
        print_table(self.out_map)

    # -------------------------------- Private ------------------------------- #

    def check_file(self, map):
        temp = set(map.replace('\n', ''))
        if len(temp) != 4:
            error("Wrong file formatting")
        for (_, char) in enumerate(temp):
            if char != 'F' and char != 'P' and char != '1' and char != '0':
                error(f"Bad character found in file: {char}")


    def find_nodes(self, cStart = 'F', cEnd = 'P'):
        for x in range(len(self.in_map)):
            for y in range(len(self.in_map[x])):
                if (self.in_map[x][y] == cStart):
                    self.start = Node(x, y, cStart)
                elif (self.in_map[x][y] == cEnd):
                    self.end = Node(x, y, cEnd)


    def traverse_map(self, curr, depth, dir = 0):
        ''' Custom shortest path algorithm on a map going from start to end '''
        curr.c = self.out_map[curr.x][curr.y]
        isInt = False

        try:
            tmp = int(curr.c)
            isInt = bool(tmp >= 0 and tmp <= 9)
        except ValueError:
            isInt = False
        if curr.c != self.air and not isInt and depth != 0 and curr.c == self.start.c:
            return False
        if curr == self.end:
            return True
        if depth > 0:
            self.out_map[curr.x][curr.y] = depth
        # print_table(self.out_map)
        # print(f"{curr.x}, {curr.y}\n")

        if dir == 0 and self.traverse_map(Node(curr.x - 1, curr.y), depth + 1, (dir + 1) % 4):
            return True
        if dir == 1 and self.traverse_map(Node(curr.x, curr.y + 1), depth + 1, (dir + 1) % 4):
            return True
        if dir == 2 and self.traverse_map(Node(curr.x + 1, curr.y), depth + 1, (dir + 1) % 4):
            return True
        if dir == 3 and self.traverse_map(Node(curr.x, curr.y - 1), depth + 1, (dir + 1) % 4):
            return True
        return False
