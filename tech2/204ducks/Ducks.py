##
## EPITECH PROJECT, 2022
## 204ducks
## File description:
## Ducks
##

SECONDS = 60

from math import sqrt, exp, pow

from utils import average, deviation

class Ducks:
    # -------------------------------- Public -------------------------------- #

    def __init__(self):
        self.t = self._init_time(0)
        self.average = self._init_time(0)
        self.deviation = 0.0

        self.back = {
            't': {
                '50': self._init_time(0),
                '99': self._init_time(0),
            },
            'p': {
                '1': 0.0,
                '2': 0.0,
            }
        }
        

    def set_time(self, t):
        """ Sets self.t to t and updates related values """
        self.t         = self._init_time(t)
        self.average   = self._init_time(average(  self.t['full_m']))
        self.deviation = self._init_time(deviation(self.t['full_m']))


    def print(self):
        """ Main prints """
        print(f"Average return time: {self._format_m_s(self.average)}")
        print(f"Standard deviation: {self.deviation['full_m']:.3f}")
        print(f"Time after which 50% of the ducks are back: {self._format_m_s(self.back['t']['50'])}")
        print(f"Time after which 99% of the ducks are back: {self._format_m_s(self.back['t']['99'])}")
        print(f"Percentage of ducks back after 1 minute: {round(self.back['p']['1'], 1)}%")
        print(f"Percentage of ducks back after 2 minutes: {round(self.back['p']['2'], 1)}%")

    # -------------------------------- Private ------------------------------- #

    def _init_time(self, t):
        """ Given a t, decomposes it into minutes and seconds """
        """ But also a true seconds and the default value """
        return {
            'full_m': t,                # -> float, minutes
            'm': int(t // 1),           # -> partie entiere
            's': (t % 1) * SECONDS,     # -> partie décimale
            'full_s': (t // 1) * SECONDS + ((t % 1) * SECONDS)
        }


    def _format_m_s(self, t):
        """ Format a given t to MINm SECs """
        return f"{t['m']}m {int(round(t['s'])):02d}s"


    def _wolfram_alpha(self):
        b = 0.001
        res = 0.0
        fifty = True
        ninety = True
        
        while b < 2 or res <= 99:
            var1 = (1 / 2) * exp(-4 * b)
            var2 = pow(exp(b) - 1, 2)
            var3 = 2 * pow(exp(b) + 1, 2)
            var4 = self.t['full_m'] * (2 * exp(b) + 1)
            res  = var1 * var2 * (var3 - var4)

            res *= 100.0
            if fifty and res >= 50:
                fifty = False
                self.back['t']['50'] = self._init_time(round(b, 3))
            if ninety and res >= 99:
                ninety = False
                self.back['t']['99'] = self._init_time(round(b, 3))
            if round(b, 3) == 1.00:
                self.back['p']['1'] = res
            if round(b, 3) == 2:
                self.back['p']['2'] = res
            b += 0.001
