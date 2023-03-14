##
## EPITECH PROJECT, 2022
## Gomoku (Workspace)
## File description:
## Node
##

class Node:
    def __init__(self, x, y, size, pid):
        if x < 0 or y < 0 or x >= size or y >= size:
            raise Exception("Node: Out of bounds")
        self.x = x
        self.y = y

        if pid < 0 and pid > 2:
            raise Exception("Node: Unknown player ID")
        self.pid = pid

        #! -> int -> direction -> [x,y] E [-1, 0, 1] -> x = id%3 - 1, y = id//3 - 1
        #!  x + 1 + (y + 1) * 3 = id = 8 - opposed
        #! Ex:
        #!   0 1 2
        #!   3 4 5
        #!   6 7 8
        self.neighbors = [
            [x - 1, y - 1] if x > 0 and y > 0 else False,
            [x,     y - 1] if y > 0 else False,
            [x + 1, y - 1] if y > 0 and x < size - 1 else False,

            [x - 1, y    ] if x > 0 else False,
            [x    , y    ],
            [x + 1, y    ] if x < size - 1 else False,

            [x - 1, y + 1] if x > 0 and y < size - 1 else False,
            [x    , y + 1] if y < size - 1 else False,
            [x + 1, y + 1] if y < size - 1 and x < size - 1 else False
        ]
        self.lines = [False, False, False, False]


        #* neighbors -> playables (vides)
        #*           -> ally (chain) NMI(blocked)
        #* direction -> ???
        #* sizeS     -> direction
        #* connect   -> direction + sizes + playables
        self.size = [0, 0, 0, 0]
        self.weight = [0, 0]


    def __str__(self):
        return f"({self.x},{self.y},{self.pid})"

    # -------------------------------- Public -------------------------------- #

    def play(self, pid, board_state):
        self.pid = pid
        for k in range(0, 4):
            sizeL = self.getSize(k,     pid, board_state)
            sizeR = self.getSize(8 - k, pid, board_state)
            size  = 1 + sizeL + sizeR
            self.size[k] = size


    def getMaxWeight(self):
        if self.weight[0] >= self.weight[1]:
            return (self.weight[0] + 1)
        else:
            return self.weight[1]

    def getSize(self, k, pid, board_state, otrPid = -1):
        pos  = self.neighbors[k]
        dist = 0
        while pos and (board_state[pos[1]][pos[0]].pid == pid or board_state[pos[1]][pos[0]].pid == otrPid):
            pos  = board_state[pos[1]][pos[0]].neighbors[k]
            dist = dist + 1
        return dist


    def getLastNeigh(self, k, board_state):
        ext = self.neighbors[4]
        pos = self.neighbors[k]
        while pos and board_state[pos[1]][pos[0]].pid == self.pid:
            ext = pos
            pos = board_state[pos[1]][pos[0]].neighbors[k]
        return ext


    def log(self):
        size = max(self.size)
        return (f"{size}")