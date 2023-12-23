class Graph {
  List<Edge> edges = [];
  int vertices;

  Graph(this.vertices);

  void addEdge(int source, int destination, int weight) {
    edges.add(Edge(source, destination, weight));
  }

  List<Edge> kruskal() {
    edges.sort((a, b) => a.weight - b.weight);

    List<Edge> result = [];
    List<int> parent = List.generate(vertices, (index) => index);

    int find(int vertex) {
      if (parent[vertex] != vertex) {
        parent[vertex] = find(parent[vertex]);
      }
      return parent[vertex];
    }

    void union(int x, int y) {
      int rootX = find(x);
      int rootY = find(y);
      parent[rootX] = rootY;
    }

    for (Edge edge in edges) {
      int rootSource = find(edge.source);
      int rootDestination = find(edge.destination);

      if (rootSource != rootDestination) {
        result.add(edge);
        union(rootSource, rootDestination);
      }
    }

    return result;
  }
}

class Edge {
  int source, destination, weight;

  Edge(this.source, this.destination, this.weight);
}

void main() {
  Graph graph = Graph(4);

  graph.addEdge(0, 1, 10);
  graph.addEdge(0, 2, 6);
  graph.addEdge(0, 3, 5);
  graph.addEdge(1, 3, 15);
  graph.addEdge(2, 3, 4);

  List<Edge> result = graph.kruskal();

  print("Edges in the minimum spanning tree:");
  for (Edge edge in result) {
    print("${edge.source} - ${edge.destination} : ${edge.weight}");
  }
}
