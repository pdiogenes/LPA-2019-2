import math

def getAnswer(path, mst):
    maior = float('-inf')
    for i in range (1, len(path)):
        for j in mst[path[i-1]]:
            if path[i] == j[0]:
                if j[1] > maior:
                    maior = j[1]

    print(maior)


def DFSUtil(mst, u, d, visited, path):
        visited[u]= True
        path.append(u)
        if u ==d:
            getAnswer(path,mst)
        else:
            for i in mst[u]:
                if visited[i[0]]==False:
                    DFSUtil(mst, i[0], d, visited, path)
        path.pop()
        visited[u]= False

def DFS(mst,s, d):
    visited =[False]*(len(mst))
    path = []
    DFSUtil(mst, s, d,visited, path)
    return path

def union(parent, rank, x, y):
    yroot = find(parent, x)
    xroot = find(parent, y)

    if rank[xroot] < rank[yroot]:
        parent[xroot] = yroot
    elif rank[xroot] > rank[yroot]:
        parent[yroot] = xroot
    else:
        parent[yroot] = xroot
        rank[xroot] += 1

def find(parent, i):
    if parent[i] == i:
        return i
    return find(parent, parent[i])

def kruskal(grafo, n):
    resultado = {i:[] for i in range(n)}
    i = 0
    e = 0
    grafo2 = sorted(grafo, key=lambda item: item[2])

    parent = []
    rank = []

    for x in range(n):
        parent.append(x)
        rank.append(0)

    while e < (n - 1):
        u, v, w = grafo2[i]
        i = i + 1
        x = find(parent, u)
        y = find(parent, v)

        if x != y:
            e = e + 1
            resultado[u].append([v, w])
            resultado[v].append([u, w])
            union(parent, rank, x, y)

    #print(resultado)
    return resultado

def addEdge(grafo, s, d, h):
    grafo.append([s, d, h])

def main():
    count = 1
    while True:
        n, m = map(int, input().split())
        if(n == 0) and (m == 0):
            break
        if n >= 0 and n <= 100 and m >= 0 and m <= 4950:
            print("Instancia", count)
            grafo = []

            for i in range(m):
                i, j, h = map(int, input().split())
                if i >= 1 and j <= n:
                    addEdge(grafo, i-1, j-1, h)

            resp = {}
            mst = kruskal(grafo, n)

            k = int(input())
            if k >= 1 and k <= 50:
                for x in range(k):
                    i, j = map(int, input().split())
                    if i == j:
                        print(0)
                    else:
                        DFS(mst, i-1, j-1)

            count+=1
            print()


main()
