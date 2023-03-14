##
## EPITECH PROJECT, 2022
## pbrain-gomoku-ai
## File description:
## Main
##

from enum import Enum
import random
import time

# from src.Utils.Logger import Logger

class Status(Enum):
    UNDEFINED = 0
    STARTED   = 1
    ENDED     = 2

class Manager:
    def __init__(self, brain):
        self.brain = brain

        self.game_board = []
        self.size = -1

        self.moveScore = 0
        self.received = ""
        self.status = Status.UNDEFINED
        self.cmd = ""
        self.cmds = {
            "BEGIN": self.begin,
            "BOARD": self.board,
            "TURN": self.turn,
            "INFO": self.info,
            "ABOUT": self.about,
            "END": self.end
        }

        self.init()

    def init(self):
        data, t1 = self.get(start=True)
        self.send(data)
        data = data.split(' ')
        if data[0] == "ERROR":
            raise Exception(' '.join(data[2:]))
        for _ in range(self.size):
            line = []
            for _ in range(self.size):
                line.append('.')
            self.game_board.append(line)
        t2 = time.time()
        self.send(self.debug(t2 - t1))


    def run(self):
        while 1:
            try:
                data, t1 = self.get()
            except EOFError as e:
                self.logBoard()
                self.brain.logNodes()
                return
            except Exception as e:
                # Logger.logError(e)
                raise Exception(e)
            if self.status == Status.STARTED and data != None:
                self.send(data)
                t2 = time.time()
                self.send(self.debug(t2 - t1, data))


    #* ------------------- COMMUNICATION ------------------ *#

    def get(self, start=False):
        self.cmd = input()
        if self.cmd == "":
            raise EOFError("Received EOF, shutting down.")
        t1 = time.time()
        return self.receiveStart(self.cmd) if start else self.receive(self.cmd), t1


    def send(self, data):
        print(data, flush=True)

    #* ---------------------- PARSERS --------------------- *#

    def receiveStart(self, data):
        random.seed(time.time())
        ret = "OK"
        cmd = data.split(' ')


        if cmd[0] == "START" and len(cmd) > 1 and int(cmd[1]) > 0:
            try:
                self.size = int(cmd[1])
                self.brain = self.brain(self.size, 1)
            except:
                ret = self.error("Unsupported size")
            # Logger.logInfo(f"Initialized map of size {self.size}")
        else:
            if len(cmd) > 1 and int(cmd[1]) <= 0:
                ret = self.error("START: Wrong board size")
            else:
                ret = self.error(f"Expected \"START\", got \"{cmd[0]}\"")
        self.status = Status.STARTED
        return ret


    def receive(self, data):
        # Logger.logInfo(f"Received: {data}")
        try:
            cmd = data.split(' ')
        except:
            # Logger.logWarning(f"Received wrong command format: \"{data}\"")
            return self.error(f"Received wrong command format: \"{data}\"")

        if cmd[0] not in self.cmds:
            # Logger.logWarning(f"Command \"{cmd[0]}\" not found")
            return self.unknown(cmd[0])
        self.received = cmd[1:]
        return self.cmds[cmd[0]]()

    #* ----------------------- UTILS ---------------------- *#

    def logBoard(self):
        ret = "Board:\n"

        for lines in self.game_board:
            for c in lines:
                ret += str(c) + " "
            ret += "\n"
        # Logger.logDebug(ret)


    def readMultiLine(self):
        self.received = ""
        data = input()
        while data != "DONE":
            self.received = self.received + data + '\n'
            data = input()

    #* --------------------- COMMANDS --------------------- *#

    def begin(self):
        (x, y, score) = self.brain.getMove()
        self.brain.play(x, y, 1, False)
        self.game_board[y][x] = 1
        self.moveScore = score
        pos = f"{x},{y}"
        # Logger.logInfo(f"Turn: {pos}")
        self.status = Status.STARTED
        return pos


    def board(self):
        self.readMultiLine()
        self.play = True
        lines = list(filter(None, self.received.split('\n')))

        for line in lines:
            words = line.split(',')
            if len(words) != 3:
                return self.error("BOARD: Bad syntax for multi-line command")
            try:
                x = int(words[0])
                y = int(words[1])
                p = int(words[2])

                if self.game_board[y][x] != '.' or p < 0 or p > 2:
                    raise Exception
                self.game_board[y][x] = p
            except:
                return self.error("BOARD: Wrong board placement")
        self.brain.loadBoard(self.game_board)
        (x, y, score) = self.brain.getMove()
        self.moveScore = score
        pos = f"{x},{y}"
        self.brain.play(x, y, 1, True)
        self.game_board[y][x] = 1
        # Logger.logInfo(f"Turn: {pos}")
        self.status = Status.STARTED
        return pos


    def turn(self):
        try:
            pos = self.received[0].split(',')
        except:
            return self.error("TURN: Bad arguments count")

        try:
            x = int(pos[0])
            y = int(pos[1])

            if self.game_board[y][x] != '.':
                raise Exception
            self.game_board[y][x] = 2
        except:
            raise Exception(f"TURN: Wrong placement: ({pos[0]},{pos[1]}) node node is {self.game_board[y][x]}")
        self.brain.play(x, y, 2, True)
        (xx, yy, score) = self.brain.getMove()
        self.moveScore = score
        self.brain.play(xx, yy, 1, False)
        self.game_board[yy][xx] = 1
        newPos = f"{xx},{yy}"
        # Logger.logInfo(f"Turn: {newPos}")
        self.logBoard()
        return newPos


    def info(self):
        key = self.received[0]
        value = self.received[1]
        # Logger.logInfo(f"Info: {key} = {value}")
        # TODO: Link to brain
        # self.brain.updateInfo(key, value)
        return ""


    def about(self):
        ret = self.brain.getAbout()
        # Logger.logInfo("About: " + ret)
        return ret


    def end(self):
        # TODO: delete temp files
        # Logger.logInfo("End command received, Brain shutting down.")
        self.brain.dumpLines()
        self.brain.logPOIs()
        self.status = Status.ENDED
        raise EOFError

    #* ------------------ BRAIN COMMANDS ------------------ *#


    def unknown(self, cmd):
        return f"UNKNOWN Command \"{cmd}\" not found"


    def error(self, msg):
        return f"ERROR {msg}"


    def message(self, msg):
        return f"MESSAGE {msg}"


    def debug(self, dt = .0, data = ""):
        cmd = self.cmd.split(' ')[0]
        if cmd == "TURN" or cmd == "BEGIN" or cmd == "BOARD":
            info = f"Brain made a move at [{data}] score={self.moveScore} "
        elif cmd == "ABOUT":
            info = f"Brain info: {data} "
        elif cmd == "START":
            info = f"Brain ready! (size: {self.size}) "
        else:
            info = ""
        return f"DEBUG {info}(elapsed: {dt:.2f}s)"


    def suggest(self, x, y):
        return f"SUGGEST {x},{y}"
