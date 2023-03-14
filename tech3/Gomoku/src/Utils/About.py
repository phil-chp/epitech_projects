##
## EPITECH PROJECT, 2022
## Gomoku (Workspace)
## File description:
## About
##

class About:
    def __init__(self, name, version, authors, country):
        self.name    = name
        self.version = version
        self.author  = list(authors)
        self.country = country

    def __str__(self):
        return f"name=\"{self.name}\", version={self.version}, authors={self.author}, country={self.country}"

    # -------------------------------- Public -------------------------------- #

    # -------------------------------- Private ------------------------------- #
