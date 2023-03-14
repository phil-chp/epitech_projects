##
## EPITECH PROJECT, 2022
## Gomoku (Workspace)
## File description:
## Brain
##

# from src.Utils.Logger import Logger
from src.Utils.About import About
from src.Structures.Node import Node
from src.Structures.Line import Line
from src.Predicter import Predicter

class Brain:
    def __init__(self, board_size, pid):
        self.board_size = board_size
        self.pid = pid
        self.otr_pid = 2 if pid == 1 else 1
        
        self.last_played = []
        self.lines_to_watch = [[], []]
        self.allLines = []
        self.nodes = []
        self.POI = []
        self.predicter = Predicter(3)
        self.about = About(
            "BrainLag",
            1.0,
            [ "Adrian", "Philippe", "Quentin" ],
            "FR"
        )
        for y in range (0, self.board_size):
            line = []
            for x in range (0, self.board_size):
                line.append(Node(x, y, self.board_size, 0))
            self.nodes.append(line)
        self.predicter.updateData(self)
        self.logNodes()


    def initLine(self, node, k):
        posMin  = node.getLastNeigh(k,     self.nodes)
        posMax  = node.getLastNeigh(8 - k, self.nodes)

        line        = Line(k, posMin, posMax, node.size[k], node.pid)
        line.id     = len(self.allLines)
        line.checkDead(self.nodes)
        self.allLines.append(line)
        return line


    def createLines(self, x, y):
        node = self.nodes[y][x]

        for k in range(0, 4):
            if node.size[k] <= 1:
                continue
            line = self.initLine(node, k)
            toReplace = line.assign(self.nodes)

            for id in toReplace:
                self.allLines[id].dead = True
                if id in self.lines_to_watch[node.pid - 1]:
                    el = self.lines_to_watch[node.pid - 1].index(id)
                    self.lines_to_watch[node.pid - 1][el] = line.id

    def updatePOI(self):
        for poi in self.POI:
            self.nodes[poi[1]][poi[0]].weight[0] = 0
            self.nodes[poi[1]][poi[0]].weight[1] = 0
        self.POI   = []
        imperative = []
        carreful = []
        
        for line in self.allLines:
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
                if self.nodes[posMax[1]][posMax[0]].weight[line.pid - 1]  <= size * 2:
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


    def play(self, x, y, pid, refresh):
        self.nodes[y][x].play(pid, self.nodes)
        self.last_played.append([x, y, pid])
        if max(self.nodes[y][x].size) > 1:
            self.createLines(x, y)
        if max(self.nodes[y][x].size) > 4:
            # Logger.logInfo("Brain won.")
            # TODO: End Game
            pass
        if refresh:
            self.updatePOI()
        self.logNodes()


    def getAbout(self):
        return self.about

        
    def logNodes(self):
        ret = "Board:\n"

        for lines in self.nodes:
            for c in lines:
                ret += str(c) + " "
            ret += "\n"
        # Logger.logDebug(ret)


    def logPOIs(self):
        for point in self.POI:
            node = self.nodes[point[1]][point[0]]
            # Logger.logDebug(f"POI values: x={point[0]}, y={point[1]}, 1={node.weight[0]}, 2={node.weight[1]}\n")
        


    def loadBoard(self, board_map):
        for y, line in enumerate(board_map):
            for x, c in enumerate(line):
                if c != '.':
                    self.play(x, y, int(c), False)
        self.updatePOI()
        self.predicter.updateData(self)
        self.logNodes()


    def dumpLines(self):
        for line in self.allLines:
            line.dump()


    def getMove(self):
        (play_line, score) = self.predicter.predict(self)
        if score == -1:
            pass
            # print("Yo tu vas perdre frero")
        # print(play_line)
        if play_line == []:
            pos = self.predicter.data.playRandom(1)
            return (pos[1], pos[0], 0)
        # print("My Turn is", play_line[0][1], " : ", play_line[0][0], "score = ", score)
        # print (play_line)
        return (play_line[0], play_line[1], score)
