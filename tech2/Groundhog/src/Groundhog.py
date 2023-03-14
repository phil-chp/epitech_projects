##
## EPITECH PROJECT, 2022
## Groundhog (Workspace)
## File description:
## Data
##

from math import nan
from src.utils import error, moving_average, deviation
from src.utils import SUCCESS_CODE, WEIRD_TRESHOLD

class Groundhog():
    # -------------------------------- Public -------------------------------- #

    def __init__(self, period):
        self.period = period   # period of time

        self.g = [nan]         # temp increase average
        self.r = [nan]         # relative temp evolution
        self.s = [nan]         # standard deviation
        self.values = []       # list of all values inputed

        self.alert = False     # alert enable

        self.switches = 0      # number of switches
        self.weirdest = []     # weirdest values


    def run(self):
        while True:
            try:
                value = input("")
                print(value)
            except EOFError:
                self.end()
            self.update(value)


    def update(self, value):
        """ General updater to the values g r and s """
        value = self._check_value(value)

        self.values.append(value)
        self._calc_s()
        self._calc_g()
        self._calc_r()
        self._check_switch()
        self._check_weirdness(value)
        self.print()


    def print(self):
        """ General print of g r and s """
        print(f"g={self.g[-1]:.2f}", end="")
        print(f"\t\tr={self.r[-1]:.0f}%", end="")
        print(f"\t\ts={self.s[-1]:.2f}", end="")
        self._print_alert() if self.alert else print("")


    def end(self):
        """ Final print in the program """
        # count = 5 if len(self.weirdest) > 5 else len(self.weirdest)
        count = 5

        print(f"Global tendency switched {self.switches} times")
        self._sort_weirdest()
        # if count > 0:
        print(f"{count} weirdest values are {self.weirdest[-count:]}")
        # else:
        #     print("No weird values occured")
        exit(SUCCESS_CODE)

    # -------------------------------- Private ------------------------------- #

    def _print_alert(self):
        """ Prints an alert """
        print("\t\ta switch occurs")
        self.alert = False


    def _check_value(self, value):
        """ check if value is valid or STOP """
        if value == "STOP":
            self.end()
        try:
            value = float(value)
        except ValueError as e:
            error(f"Invalid value given.\n{e}")
        return value


    def _check_switch(self):
        """ Check if a switch occured """
        try:
            a = self.r[-2]
            b = self.r[-1]
        except IndexError:
            return
        if a == nan or b == nan:
            return
        if (a < 0 and b > 0) or (b < 0 and a > 0):
            self.switches += 1
            self.alert = True


    def _check_weirdness(self, value):
        """ Check if a weird value occured by checking """
        """ bollinger bounds using the z-score """
        if len(self.values) > self.period:
            avrg = moving_average(self.values, self.period)
            d = deviation(self.values, self.period, avrg)

            if d == 0:
                return
            z = (value - avrg) / d
            if abs(z) > WEIRD_TRESHOLD:
                self.weirdest.append((value, abs(z) - WEIRD_TRESHOLD))


    def _sort_weirdest(self):
        """ Sorts the weirdest values by their weird index """
        res = sorted(self.weirdest, key=lambda x: x[1], reverse=True)
        self.weirdest = []
        for i in range(len(res)):
            self.weirdest.append(res[i][0])


    def _calc_s(self):
        """ Calculate the standard deviation over the period """
        if len(self.values) >= self.period:
            average = moving_average(self.values, self.period)
            d = deviation(self.values, self.period, average)
            self.s.append(d)
        else:
            self.s.append(nan)


    def _calc_g(self):
        """ Calculate the average temp increase over the period """

        if len(self.values) > self.period:
            values = self.values[-self.period - 1:]
            increases = []

            for i in range(len(values) - 1):
                if values[i + 1] < values[i]:
                    continue
                increases.append(values[i + 1] - values[i])
            if len(increases) != 0:
                self.g.append(sum(increases) / self.period)
            else:
                self.g.append(0.00)
        else:
            self.g.append(nan)


    def _calc_r(self):
        """ Calculate the relative temperature evolution over the period """
        if len(self.values) > self.period:
            if self.values[-self.period - 1] != 0:
                evolution = (self.values[-1] - self.values[-self.period - 1])
                self.r.append(evolution / self.values[-self.period - 1] * 100)
            else:
                self.r.append(0)
        else:
            self.r.append(nan)
