maior = 0
k = 0
l = 0

class Grafo:
    def __init__(self, v):
        self.v = v
        self.grafo = {i: [] for i in range(1, v+1)}
        self.pesos = {}
        self.villages = []
        self.sum_paths = []

    def addEdge(self, from_node, to_node, weight):
        self.grafo[from_node].append(to_node)
        self.grafo[to_node].append(from_node)
        self.pesos[(from_node, to_node)] = weight
        self.pesos[(to_node, from_node)] = weight

    def printGrafo(self):
        print(self.grafo)

    def isVillage(self, a):
        self.villages = [None] * (self.v + 1)
        for edge in self.grafo:
            if edge > a:
                self.villages[edge] = False
            else:
                self.villages[edge] = True

    def printAllPathsUtil(self, u, d, visited, path):

        visited[u]= True
        path.append(u)
        if u == d:
            self.findBootUsage(path)
        else:
            for i in self.grafo[u]:
                if visited[i]==False:
                    self.printAllPathsUtil(i, d, visited, path)
        path.pop()
        visited[u]= False

    def printAllPaths(self,s, d):
        visited =[False]*(len(self.grafo) + 1)
        path = []
        self.printAllPathsUtil(s, d,visited, path)

    def findBootUsage(self, path):
        global maior, k
        botas = k
        quantia_restante = l
        final_path = []
        smaller_path = []
        smaller_path.append(path[0])
        for i in range(1, len(path)):
            if self.villages[path[i]]:
                smaller_path.append(path[i])
            else:
                smaller_path.append(path[i])
                final_path.append(smaller_path)
                smaller_path = []
                smaller_path.append(path[i])
        final_path.append(smaller_path)

        sub_costs = []
        costs = []
        for sub_path in final_path:
            sub_costs = []
            for i in range (1, len(sub_path)):
                sub_costs.append(self.pesos[(sub_path[i-1],sub_path[i])])
            costs.append(sub_costs)

        sub = 0
        soma = 0
        for partial in costs:
            soma += sum(partial)

        for sub_cost in costs:
            if botas > 0:
                teste = False
                for i in range(0, len(sub_cost) + 1):
                    for j in range(i, len(sub_cost) + 1):
                        for h in range(i, j):
                            sub += sub_cost[h]
                        if sub > maior and sub <= quantia_restante:
                            teste = True
                            quantia_restante -= sub
                            maior = sub
                        sub = 0
                        quantia_restante = l
                if teste: botas -= 1
            botas = k
        self.sum_paths.append(soma - maior)

    def printResp(self):
        print(min(self.sum_paths))


def main():
    t = int(input())
    if t >= 1 and t <= 20:
        while t > 0:
            global k, l
            a, b, m, l, k = map(int, input().split())
            if a >= 1 and a <= 50 and l >= 1 and l <= 500 and k >= 0 and k <= 10:
                g = Grafo(a+b)
                for i in range(m):
                    xi, yi, li = map(int, input().split())
                    if li >= 1 and li <= 100:
                        g.addEdge(xi, yi, li)

                g.isVillage(a)

                starting_vertex = a+b
                end_vertex = 1
                g.printAllPaths(starting_vertex, end_vertex)
                g.printResp()

            t -= 1

#main
main()
