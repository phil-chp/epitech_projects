##
## EPITECH PROJECT, 2022
## Gomoku (Workspace)
## File description:
## utils
##

def rules():
    print("BRAIN MANDATORY COMMANDS")
    print("\n\nSTART [size]")
    print("\tsize\tsize of the board (square)")
    print("\n\t\tREPLIES")
    print("\t\tOK")
    print("\t\tERROR [message]")
    print("\n\nTURN [x],[y]")
    print("\tx,y\tCoordinates of the opponent's move")
    print("\n\t\tREPLY")
    print("\t\tx',y'\tCoordinates of the brain's move")
    print("\n\nBEGIN")
    print("\n\t\tREPLY")
    print("\t\tx',y'\tCoordinates of the brain's move")
    print("\n\nBOARD")
    print("\tx,y\tCoordinates of a move")
    print("\twho\tWho made the move (1 or 2)")
    print("\n\t\tREPLY")
    print("\t\tx',y'\tCoordinates of the brain's move")
    print("\n\nINFO [key] [value]")
    print("\tkey\tcustom command, here are the available key:")
    print("\t\ttimeout_turn  - time limit for each move (milliseconds, 0=play as fast as possible)")
    print("\t\ttimeout_match - time limit of a whole match (milliseconds, 0=no limit)")
    print("\t\tmax_memory    - memory limit (bytes, 0=no limit)")
    print("\t\ttime_left     - remaining time limit of a whole match (milliseconds)")
    print("\t\tgame_type     - 0=opponent is human, 1=opponent is brain, 2=tournament, 3=network tournament")
    print("\t\trule          - bitmask or sum of 1=exactly five in a row win, 2=continuous game, 4=renju")
    print("\t\tevaluate      - coordinates X,Y representing current position of the mouse cursor")
    print("\t\tfolder        - folder for persistent files")
    print("\tvalue\tthe value assigned to the key")
    print("\n\t\tREPLY")
    print("\t\tNone")
    print("\n\nEND")
    print("\n\t\tREPLY")
    print("\t\tNone")
    print("\n\nABOUT")
    print("\n\t\tREPLY")
    print("\t\tname=\"SomeBrain\", version=\"1.0\", author=\"Nymand\", country=\"USA\"")
    return


def test(man):
    print("Test 1:\n\tSending:\tSTART 20\n\tExpecting:\tOK\n\tReceived:\t", end="")
    man.receive("START 20")

    print("Test 2:\n\tSending:\tBEGIN\n\tExpecting:\tx,y\n\tReceived:\t", end="")
    man.receive("BEGIN")

    print("Test 3:\n\tSending:\tBOARD ?????\n\tExpecting:\tx,y\n\tReceived:\t", end="")
    man.receive("BOARD")

    print("Test 4:\n\tSending:\tINFO ?????\n\tExpecting:\t[Nothing]\n\tReceived:\t", end="")
    man.receive("INFO")

    print("Test 5:\n\tSending:\tABOUT\n\tExpecting:\t?????\n\tReceived:\t", end="")
    man.receive("ABOUT")

    print("Test 6:\n\tSending:\tEND\n\tExpecting:\t[Nothing]\n\tReceived:\t", end="")
    man.receive("END")
