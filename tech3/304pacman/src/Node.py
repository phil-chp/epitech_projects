##
## EPITECH PROJECT, 2022
## 304pacman (Workspace)
## File description:
## Node
##

class Node:
    def __init__(self, x, y, c = ''):
        self.c = c
        self.x = x
        self.y = y

    def __str__(self):
        return f"[ {self.c}, ({self.x}, {self.y}) ]"

    def __eq__(self, other):
        """Overrides the default implementation"""
        if isinstance(other, Node):
            return self.x == other.x and self.y == other.y
        return False

    # -------------------------------- Public -------------------------------- #

    def get_pos(self):
        return (self.x, self.y)
