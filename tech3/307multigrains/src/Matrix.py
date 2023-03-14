##
## EPITECH PROJECT, 2023
## 307multigrains (Workspace)
## File description:
## Matrix
##

class Matrix:
    @staticmethod
    def get_matrix(data, gpt):
        """ Get the matrix """
        M = [[] for _ in range(0, 5)]

        for _, (_, value) in enumerate(gpt.items()):
            for i in range(0, 4):
                M[i].append(value[i])

        for i in range(0, 4):
            M[i].extend([0, 0, 0, 0])
            M[i][5 + i] = 1
            M[i].append(data.tons[i])

        M[4].extend([-p for p in data.prices])
        M[4].extend([0, 0, 0, 0, 0])

        return M
