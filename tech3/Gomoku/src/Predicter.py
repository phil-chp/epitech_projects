##
## EPITECH PROJECT, 2022
## B-AIA-500-NCE-5-1-gomoku-philippe.cheype [WSL : Ubuntu]
## File description:
## Predicter
##

import random
from copy import deepcopy

from src.Structures.Line import Line
# from src.Utils.Logger import Logger

#* ----------------- PREDICT DATA ---------------- *#

class PredictData:
    def __init__(self, brain):
        self.nodes     = brain.nodes
        self.lines     = brain.allLines
        self.POI       = brain.POI
        self.turn      = 0
        self.firstData = None
        self.last_played = []
        self.rec = 0

    
    def isEnd(self):
        for line in self.lines:
            if line.size >= 5:
                return line.pid
        return 0


    def play(self, point, pid, turn):
        # print("PLAY PREDICT")
        y = point[1]
        x = point[0]
        node = self.nodes[y][x]
        node.play(pid, self.nodes)

        for k in range(0, 4):
            if node.size[k] <= 1:
                continue
            line = self.initLine(node, k)
            toReplace = line.assign(self.nodes)
            for id in toReplace:
                self.lines[id].dead = True
        if turn == 0 or turn == 1:
            self.firstData = deepcopy(self)
        # print (f"played {point}, {pid}")
        self.last_played.append(point)
        self.updatePOI()


    def updatePOI(self):
        # print("POI Predicter")
        carreful = []
        imperative = []
        for poi in self.POI:
            self.nodes[poi[1]][poi[0]].weight[0] = 0
            self.nodes[poi[1]][poi[0]].weight[1] = 0
        self.POI = []
        for line in self.lines:
            if line.dead:
                continue
            line.checkDead(self.nodes)
            if line.dead:
                continue
            posMin = self.nodes[line.extMin[1]][line.extMin[0]].neighbors[line.dir]
            posMax = self.nodes[line.extMax[1]][line.extMax[0]].neighbors[8 - line.dir]
            if line.spaceL > 0:
                dist = self.nodes[posMin[1]][posMin[0]].getSize(line.dir, line.pid, self.nodes)
                # if dist != 0:
                #     Logger.logDebug(f"brain dist={dist}, size={size}")
                size = line.size + 1 + dist
                if self.nodes[posMin[1]][posMin[0]].weight[line.pid - 1] <= size * 2:
                    if size > 4 :
                        self.nodes[posMin[1]][posMin[0]].weight[line.pid - 1] = 100
                        if posMin not in imperative:
                            imperative.append(posMin)
                    elif size == 4 and line.spaceR > 0 and line.spaceL > 1 + dist:
                        self.nodes[posMin[1]][posMin[0]].weight[line.pid - 1] = size * 2
                        if posMin not in carreful:
                            carreful.append(posMin)
                    else:
                        self.nodes[posMin[1]][posMin[0]].weight[line.pid - 1] = size * 2
                        if posMin not in self.POI:
                            self.POI.append(posMin)

            if line.spaceR > 0:
                dist = self.nodes[posMax[1]][posMax[0]].getSize(8 - line.dir, line.pid, self.nodes)
                # if dist != 0:
                #     Logger.logDebug(f"brain dist={dist}, size={size}")
                size = line.size + 1 + dist
                if self.nodes[posMax[1]][posMax[0]].weight[line.pid - 1] <= size * 2:
                    if size > 4:
                        self.nodes[posMax[1]][posMax[0]].weight[line.pid - 1] = 100
                        if posMax not in imperative:
                            imperative.append(posMax)
                    elif size == 4 and line.spaceL > 0 and line.spaceR > 1 + dist:
                        self.nodes[posMax[1]][posMax[0]].weight[line.pid - 1] = size * 2
                        if posMax not in carreful:
                            carreful.append(posMax)
                    else:
                        self.nodes[posMax[1]][posMax[0]].weight[line.pid - 1] = size * 2
                        if posMax not in self.POI:
                            self.POI.append(posMax)

        if carreful != []:
            self.POI = carreful
        if imperative != []:
            self.POI = imperative
        self.POI.sort(key=lambda x: self.nodes[x[1]][x[0]].getMaxWeight(), reverse=True)

    def initLine(self, node, k):
        posMin  = node.getLastNeigh(k,     self.nodes)
        posMax  = node.getLastNeigh(8 - k, self.nodes)

        line        = Line(k, posMin, posMax, node.size[k], node.pid)
        line.id     = len(self.lines)
        line.checkDead(self.nodes)
        self.lines.append(line)
        return line
        
    def playRandom(self, pid):
        ret = []
        point = []
        friend = []
        for y, line in enumerate(self.nodes):
            for x, node in enumerate(line):
                if node.pid == 0:
                    point.append([x, y])
                elif node.pid == pid:
                    friend.append([x, y])
        if friend != []:
            for point in friend:
                # print(f"friendPoint = {point}")
                node = self.nodes[point[1]][point[0]]
                if node:
                    k = random.randint(0, 8)
                    nb = 0
                    while nb < 8 :
                        if node.neighbors[k] and self.nodes[node.neighbors[k][1]][node.neighbors[k][0]] and self.nodes[node.neighbors[k][1]][node.neighbors[k][0]].pid == 0:
                            ret =  node.neighbors[k]
                            break
                        k = (k + 1) % 8
                        nb += 1
        if ret == [] and len(point) != 0:
            ret = random.choice(point)
        return ret

#* ------------------ PREDICTER ------------------ *#

class Predicter:
    def __init__(self, maxTurn):
        self.maxTurnPredict = maxTurn
        self.predicted = []
        self.data = None


    def updateData(self, brain):
        self.data = PredictData(brain)
        # print (f"new data: {self.data}")


    def predict(self, brain):
        self.rec = 0
        
        self.updateData(brain)
        if self.data.POI == []:
            return (self.data.playRandom(1), 0)
        (maxScore, maxData) = self.max(self.data, 0)
        return (maxData.last_played[0], maxScore)


    def min(self, data, turn): # ENNEMY TURN
        end = data.isEnd()

        if end == 2:
            return (-1, data)
        elif end == 1:
            return (1, data)
        elif turn >= self.maxTurnPredict:
            return (0, data)
 
        minValue = 2
        retData = data

        for nb, point in enumerate(data.POI):
            if nb > 5:
                break
            newData = deepcopy(data)
            newData.play(point, 2, turn)
            
            (maxSc, maxData) = self.max(newData, turn + 1)
            if maxSc < minValue:
                retData = maxData
                minValue = maxSc
        if minValue == 2:
            minValue = 0
        return (minValue, retData)

    def max(self, data, turn):  # MY TURN
        self.rec += 1
        end = data.isEnd()

        if end == 1 :
            return ( 1, data)
        elif end == 2 :
            return (-1, data)
        elif turn >= self.maxTurnPredict:
            return (0, data) 

        maxValue = -2
        retData = data

        for nb, point in enumerate(data.POI):
            if nb > 5:
                break

            newData = deepcopy(data)
            newData.play(point, 1, turn)
            (minSc, minData) = self.min(newData, turn + 1)
            if minSc > maxValue:
                retData = minData
                maxValue = minSc
        if maxValue == -2:
            maxValue = 0
        return (maxValue, retData)
