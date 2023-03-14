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

def main():
    period = argument_parsing(argv)
    groundhog = Groundhog(period)
    groundhog.run()
    return 0

if __name__ == '__main__':
    main()
