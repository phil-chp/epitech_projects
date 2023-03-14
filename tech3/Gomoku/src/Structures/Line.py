##
## EPITECH PROJECT, 2022
## Gomoku (Workspace)
## File description:
## Line
##

# from src.Utils.Logger import Logger

class Line:
    def __init__(self, dir, extMin, extMax, size, pid):
        self.dir     = dir

        self.extMin  = extMin
        self.extMax  = extMax

        self.size    = size
        self.spaceL  = -1
        self.spaceR  = -1
        self.pid     = pid

        self.dead    = False
        self.id      = -1

    # -------------------------------- Public -------------------------------- #

    def checkDead(self, nodes):
        nodeMin = nodes[self.extMin[1]][self.extMin[0]]
        nodeMax = nodes[self.extMax[1]][self.extMax[0]]
        self.spaceL = nodeMin.getSize(self.dir,     self.pid, nodes, 0)
        self.spaceR = nodeMax.getSize(8 - self.dir, self.pid, nodes, 0)
        if self.spaceL + self.spaceR + self.size < 5:
            self.dead = True

    def assign(self, nodes):
        ret = []
        pos = self.extMax
        for _ in range(0, self.size):
            nodes[pos[1]][pos[0]].size[self.dir] = self.size
            if nodes[pos[1]][pos[0]].lines[self.dir] != False:
                ret.append(nodes[pos[1]][pos[0]].lines[self.dir])
            nodes[pos[1]][pos[0]].lines[self.dir] = self.id
            pos = nodes[pos[1]][pos[0]].neighbors[self.dir]
        return ret

    def dump(self):
        # Logger.logDebug(f"Line values: size={self.size}, start={self.extMin}, finish={self.extMax}, dir={self.dir}, dead={self.dead}")
        pass

    # -------------------------------- Private ------------------------------- #
