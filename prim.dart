class Graph {
  late int vertices;
  late List<List<int>> matrix;

  Graph(int vertices) {
    this.vertices = vertices;
    matrix = List.generate(vertices, (i) => List<int>.filled(vertices, 0));
  }

  void addEdge(int source, int destination, int weight) {
    matrix[source][destination] = weight;
    matrix[destination][source] = weight;
  }

  void primMST() {
    List<bool> inMST = List.filled(vertices, false);
    List<int> key = List.filled(vertices, 999999); // Use a large value instead of infinity
    List<int> parent = List.filled(vertices, -1);

    // Start with the first vertex
    key[0] = 0;

    for (int count = 0; count < vertices - 1; count++) {
      int u = minKey(key, inMST);
      inMST[u] = true;

      for (int v = 0; v < vertices; v++) {
        if (matrix[u][v] != 0 && !inMST[v] && matrix[u][v] < key[v]) {
          parent[v] = u;
          key[v] = matrix[u][v];
        }
      }
    }

    printMST(parent);
  }

  int minKey(List<int> key, List<bool> inMST) {
    int min = 999999; // Use a large value instead of infinity
    int minIndex = -1;

    for (int v = 0; v < vertices; v++) {
      if (!inMST[v] && key[v] < min) {
        min = key[v];
        minIndex = v;
      }
    }

    return minIndex;
  }

  void printMST(List<int> parent) {
    print("Edge \tWeight");
    for (int i = 1; i < vertices; i++) {
      print("${parent[i]} - $i \t${matrix[i][parent[i]]}");
    }
  }
}

void main() {
  Graph graph = Graph(5);

  graph.addEdge(0, 1, 2);
  graph.addEdge(0, 3, 6);
  graph.addEdge(1, 2, 3);
  graph.addEdge(1, 3, 8);
  graph.addEdge(1, 4, 5);
  graph.addEdge(2, 4, 7);
  graph.addEdge(3, 4, 9);

  graph.primMST();
}
