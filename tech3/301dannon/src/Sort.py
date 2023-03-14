##
## EPITECH PROJECT, 2022
## 301dannon (Workspace)
## File description:
## Sort
##

LOWEST_FIRST = lambda x, y: x < y

class Sort:
    def __init__(self):
        self.merge_count = 0

    def select(self, L, key=LOWEST_FIRST):
        """ Select sort """
        iteration = 0

        length = len(L)
        for i in range(0, length):
            tmp = i
            for j in range(i + 1, length):

                iteration = iteration + 1
                if L[tmp] > L[j]:
                    tmp = j
            L[i], L[tmp] = L[tmp], L[i]
        return [L, iteration]


    def insert(self, L, key=LOWEST_FIRST):

        l = len(L)
        iteration = 0
        for i in range(1, l):
            j = i
            while j > 0:
                iteration += 1
                if L[j - 1] <= L[j]:
                    L[j], L[j - 1] = L[j - 1], L[j]
                    j -= 1
                else:
                    break
        return [L, iteration]
        # """ Insert sort """
        # iteration = 0
        # length = len(L)
        # for i in range(0, length - 1):
        #     tmp = i
        #     actu = i + 1
        #     while tmp >= 0 and L[tmp] < L[actu]:
        #         iteration = iteration + 1
        #         L[tmp], L[actu] = L[actu], L[tmp]
        #         actu, tmp = tmp, tmp - 1
        #     # iteration = iteration + 1
        # return [L, iteration]


    def bubble(self, L, key=LOWEST_FIRST):
        """ Bubble sort """
        iteration = 0

        length = len(L)
        for j in range(0, length - 1):
            for i in range(0, length - 1 - j):
                iteration += 1
                if (L[i] > L[i + 1]):
                    L[i], L[i + 1] = L[i + 1], L[i]
        return [L, iteration]


    def quick(self, L):
        """ Quick sort """
        l = len(L)
        iteration = 0
        left, right = [], []

        if l <= 1:
            return [L, iteration]

        pivot = L[0]
        eq = [pivot]

        for i in range(1, l):
            iteration += 1
            if L[i] >= pivot:
                left.append(L[i])
            else:
                right.append(L[i])

        rl = self.quick(left)
        rr = self.quick(right)

        L = rl[0] + eq + rr[0]
        iteration += rl[1] + rr[1]

        return [L, iteration]


    def merge(self, L, key=LOWEST_FIRST):
        """ Merge sort """
        if len(L) > 1:
            m = len(L) // 2
            l = L[:m]
            r = L[m:]

            self.merge(l)
            self.merge(r)

            i = 0
            j = 0
            k = 0

            while i < len(l) and j < len(r):
                if l[i] < r[j]:
                    L[k] = l[i]
                    i += 1
                else:
                    L[k] = r[j]
                    j += 1
                k += 1
                self.merge_count += 1

            while i < len(l):
                L[k] = l[i]
                i += 1
                k += 1

            while j < len(r):
                L[k] = r[j]
                j += 1
                k += 1
        return [L, self.merge_count]