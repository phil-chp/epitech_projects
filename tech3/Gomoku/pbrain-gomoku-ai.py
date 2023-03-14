#!/usr/bin/env python3
##
## EPITECH PROJECT, 2022
## pman-gomoku-ai
## File description:
## Main
##

from sys import argv, exit
from datetime import datetime
from sys import stderr

# from src.Utils.Logger import Logger
from src.Manager      import Manager
from src.Brain        import Brain
from src.Utils.utils  import rules

def initGomoku():
    date = datetime.now()

    # Logger.init(
    #     f"{argv[0][2:]}_{date.year:02d}{date.month:02d}{date.day:02d}_{date.hour:02d}{date.minute:02d}{date.second:02d}.log"
    # )


def main():
    if len(argv) == 2 and argv[1] == "-r":
        rules()
        exit(0)
    initGomoku()
    try:
        man = Manager(Brain)
        man.run()
    except Exception as e:
        # Logger.logError(str(e))
        print(str(e), file=stderr)
        exit(84)

if __name__ == '__main__':
    main()
