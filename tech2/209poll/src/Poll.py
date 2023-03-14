


class Poll:
    def __init__(self, params):
        self.pSize  =   params[0]
        self.sSize  =   params[1]
        self.p      =   params[2]

        self.variance   = .0
        self.c95         = []
        self.c99         = []


    def print(self):
        print(f"Population size: {self.pSize}")
        print(f"Sample size: {self.sSize}")
        print(f"Voting intentions: {self.p}%")
        print(f"Variance: {self.variance:.6f}")
        if (self.c95[0] < 0):
            self.c95[0] = 0
        if (self.c95[0] > 100):
            self.c95[0] = 100
        if (self.c95[1] < 0):
            self.c95[1] = 0
        if (self.c95[1] > 100):
            self.c95[1] = 100

        if (self.c99[0] < 0):
            self.c99[0] = 0
        if (self.c99[0] > 100):
            self.c99[0] = 100
        if (self.c99[1] < 0):
            self.c99[1] = 0
        if (self.c99[1] > 100):
            self.c99[1] = 100
            
        print(f"95% confidence interval: [{self.c95[0]:.2f}%; {self.c95[1]:.2f}%]")
        print(f"99% confidence interval: [{self.c99[0]:.2f}%; {self.c99[1]:.2f}%]")
    #     Population size: 10000
    # Sample size: 500
    # Voting intentions: 42.24%
    # Variance: 0.000464
    # 95% confidence interval: [38.02%; 46.46%]
    # 99% confidence interval: [36.68%; 47.80%]


    def set_variance(self):
        p = self.p / 100
        var = (p * (1 - p))
        self.variance = ((var) / self.sSize) * ((self.pSize - self.sSize) / (self.pSize - 1))
    
    def set_confidence(self):
        self.c95.append(self.p - 100 * 1.96 * (self.variance ** 0.5))
        self.c95.append(self.p + 100 * 1.96 * (self.variance ** 0.5))
        # print(c95_amp)
        self.c99.append(self.p - 100 * 2.58 * (self.variance ** 0.5))
        self.c99.append(self.p + 100 * 2.58 * (self.variance ** 0.5))
        # print(c99_amp)

# • the 95% confidence interval amplitude is 2 × 1.96√v
# • the 99% confidence interval amplitude is 2 × 2.58√v