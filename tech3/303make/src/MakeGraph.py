##
## EPITECH PROJECT, 2022
## 303make (Workspace)
## File description:
## MakeGraph
##


from src.utils import error, print_table, get_file_content
import re

class MakeGraph:
    def __init__(self, path):
        self.fileFullContent = get_file_content(path)
        if len(self.fileFullContent) == 0:
            error("empty file")

        self.depth = 0
        self.width = 0

        self.matrix = []
        self.adjacency = []

        self.fileCommands = []
        self.elements = []

    #* ------------------------------- PUBLIC ------------------------------- *#

    def build_matrix(self):
        """ Builds the matrix """
        data = self._parse_data()
        n    = self._get_data_elements(data)
        n    = self._init_matrix(n)

        for elem in self.elements:
            for line in self.fileCommands:
                if elem in line[1:]:
                    index = self.elements.index(line[0])
                    self.matrix[n][index] = 1
                    self.adjacency.append([elem, line[0]] if line[0].find('.') != -1 else [elem])
            n = n + 1


    def build_adjacency(self):
        """ Builds the adjacency list """
        for i in range(len(self.elements)):
            self.adjacency


    def print_matrix(self):
        """ Prints the matrix """
        print_table(self.matrix)


    def print_adjacency(self):
        """ Prints the file adjacency """
        binary = re.compile(r"^(.*):").match(self.fileFullContent).group(1)
        for elem in self.adjacency:
            print(" -> ".join(elem) + " -> " + binary)

    #* ------------------------------- PRIVATE ------------------------------ *#

    def _parse_data(self):
        """ Given the raw file data, parse it into more useful data """
        message = list(filter(None, self.fileFullContent.split("\n")))
        tmp     = []
        data    = []

        for line in message:
            if re.match(re.compile(r"^.*:.*$"), line):
                data.append(tmp)
                tmp = []
            tmp.append(line)
        data.append(tmp)

        if len(data[0]) != 0:
            error("incorrect file format given")
        data.pop(0)
        return data


    def _get_data_elements(self, data):
        """ Build fileCommands and elements according to data parsed from the file """
        for line in data:
            tmp = line[0].replace(':', '')
            tmp = tmp.split(" ")
            self.fileCommands.append(tmp)
            for elem in tmp:
                self.elements.append(elem)
        self.elements = sorted(set(self.elements))
        self.fileCommands = sorted(self.fileCommands)
        return len(self.elements)


    def _init_matrix(self, size):
        """ Initialize the matrix with 0 """
        for _ in range(size):
            self.matrix.append([0] * size)
        return 0
