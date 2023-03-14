#!/usr/bin/env python3
##
## EPITECH PROJECT, 2022
## Groundhog (Workspace)
## File description:
## Data
##

from sys import argv
from src.utils import argument_parsing
from src.Groundhog import Groundhog
from bonus.Plotter import Plotter

def main():
    period    = argument_parsing(argv)
    groundhog = Groundhog(period)
    plotter   = Plotter()

    while True:
        try:
            value = input("")
        except EOFError:
            groundhog.end()
            break
        # groundhog.update(value)
        plotter.add(value)
        plotter.plot()
    return 0

if __name__ == '__main__':
    main()
