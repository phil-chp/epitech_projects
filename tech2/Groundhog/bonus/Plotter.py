##
## EPITECH PROJECT, 2022
## Groundhog (Workspace)
## File description:
## Plotter
##

import matplotlib.pyplot as plt
# import numpy as np

class Plotter:
    def __init__(self):
        fig, ax  = plt.subplots()
        self.fig = fig
        self.ax  = ax
        self.values = []
        self.time   = []

    def add(self, value):
        self.values.append(value)
        self.time.append(len(self.time) + 1)

    def plot(self):
        self.ax.plot(self.time, self.values)
        self.ax.set(
            xlabel="Time",
            ylabel="Temperature",
            title="Groundhog"
        )
        self.ax.grid()
        plt.show()

    # def run(self):
