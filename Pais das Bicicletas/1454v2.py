import math

def main():

    count = 1
    while True:
        n, m = map(int, input().split())
        if(n == 0) and (m == 0):
            break
        if n >= 0 and n <= 100 and m >= 0 and m <= 4950:
            print("Instancia", count)
            grafo = {i: [math.inf]*(n) for i in range (n)}

            for i in range(m):
                i, j, h = map(int, input().split())
                if i >= 1 and j <= n:
                    grafo[i-1][j-1] = h
                    grafo[j-1][i-1] = h

            for i in range(n):
                grafo[i][i] = 0

            for k in range(n):
                for i in range(n):
                    for j in range(n):
                        grafo[i][j] = min(grafo[i][j], max(grafo[i][k], grafo[k][j]))


            k = int(input())
            if k >= 1 and k <= 50:
                for x in range(k):
                    i, j = map(int, input().split())
                    if i == j:
                        print(0)
                    else:
                        print(grafo[i-1][j-1])

            count+=1

            print()


main()
