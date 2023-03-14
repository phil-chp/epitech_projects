##
## EPITECH PROJECT, 2022
## 205IQ
## File description:
## IQ
##

from sys import argv
from Range import Range
from utils import simpson, gaussian

class IQ:
    # -------------------------------- Public -------------------------------- #

    def __init__(self, params):
        lenParams = len(params)
        self.u = params[0]                                  # mean
        self.s = params[1]                                  # standard deviation

        min = lenParams > 2 and params[2] or 0              # minimum IQ
        max = lenParams > 3 and params[3] or 200            # maximum IQ
        self.iq = Range(min, max)                           # IQ range

        self.argCount = len(argv)                           # number of arguments


    def run(self):
        """ Main function """
        if self.argCount == 3:
            for x in range(self.iq.min, self.iq.max + 1):
                g = gaussian(x, self.u, self.s)
                self._print_gaussian(x, g)
        else:
            res = simpson(self.iq, self.u, self.s)
            self._print_simpson(res)

    # -------------------------------- Private ------------------------------- #

    def _print_gaussian(self, x, g):
        """ Prints gaussian function """
        print(f"{x} {g:.5f}")


    def _print_simpson(self, res):
        """ Prints result of simpson's rule over IQ range """
        print(f"{res:.1f}% of people have an IQ", end="")
        if self.argCount == 4:
            print(f" inferior to {self.iq.max}")
        elif self.argCount == 5:
            print(f" between {self.iq.min} and {self.iq.max}")
