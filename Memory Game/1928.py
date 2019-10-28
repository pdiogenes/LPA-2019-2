def printAllPathsUtil(grafo, u, d, visited, path):
    soma = 0
    visited[u]= True
    path.append(u)
    if u == d:
        soma = len(path) - 1
    else:
        for i in grafo[u]:
            if visited[i]==False:
                soma += printAllPathsUtil(grafo, i, d, visited, path)
    path.pop()
    visited[u]= False
    return soma

def printAllPaths(grafo,s, d):
    visited =[False]*(len(grafo)+1)
    path = []
    soma = printAllPathsUtil(grafo, s, d,visited, path)
    return soma

def addEdge(grafo, a, b):
    grafo[a].append(b)
    grafo[b].append(a)

def main():
    n = int(input())
    if n >= 2 and n <= 50000 and n % 2 == 0:
        entradas = []
        c = list(map(int,input().split()))
        grafo = {i:[] for i in range(1,n+1)}
        for i in range(n-1):
            a, b = map(int, input().split())
            addEdge(grafo, a, b)

        soma = 0
        for i in range(len(c)):
            for j in range(i, len(c)):
                if c[i] == c[j] and i != j:
                    soma += printAllPaths(grafo, i + 1, j + 1)

        print(soma)

main()
