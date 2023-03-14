##
## EPITECH PROJECT, 2022
## 305construction (Workspace)
## File description:
## Construction
##

class Construction:
    def __init__(self, data):
        self.data = [x.split(';') for x in list(filter(bool, data.split('\n')))]
        self.nodes = {}


        for d in self.data:
            if d[0] not in self.nodes:
                self.nodes[d[0]] = {}
            self.nodes[d[0]]['name'] = d[1]
            self.nodes[d[0]]['time'] = d[2]
            self.nodes[d[0]]['prereq'] = d[3:]

        print(self.nodes)

    #* ------------------------------- Public ------------------------------- *#

    def run(self):
        for node in self.nodes:
            self.predecessors_map[node] = self.get_predecessor(node)
            self.successors_map[node]   = self.get_successor(node)

    #* ------------------------------- Private ------------------------------ *#

    def _get_predecessor(self, node):
        pass
        # for n in range(len(node['prereq'])):
        #     p = self.nodes[node]['prereq']




    def _get_successor(self, node):
        pass
