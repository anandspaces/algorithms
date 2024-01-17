import sys

V = 9  # no. of vertices

def minDistance(dist, sptSet):
    min_val = sys.maxsize
    min_index = -1
    for v in range(V):
        if (not sptSet[v]) and (dist[v] <= min_val):
            min_val = dist[v]
            min_index = v
    return min_index

def printSolution(dist):
    print("Vertex \t Distance From Source")
    for i in range(V):
        print(i, " \t\t", dist[i])

def dijkstra(graph, src):
    min_val = sys.maxsize
    dist = [min_val] * V
    sptSet = [False] * V
    dist[src] = 0

    for count in range(V - 1):
        u = minDistance(dist, sptSet)
        sptSet[u] = True
        for v in range(V):
            if (not sptSet[v]) and (graph[u][v] != 0) and (dist[u] != min_val) and (dist[u] + graph[u][v] < dist[v]):
                dist[v] = dist[u] + graph[u][v]

    printSolution(dist)

if __name__ == "__main__":
    graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ]
    dijkstra(graph, 0)
