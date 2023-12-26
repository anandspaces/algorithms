import java.util.Arrays;

class Graph {
    private int vertices;
    private int[][] matrix;

    public Graph(int vertices) {
        this.vertices = vertices;
        matrix = new int[vertices][vertices];
    }

    public void addEdge(int source, int destination, int weight) {
        matrix[source][destination] = weight;
        matrix[destination][source] = weight;
    }

    public void primMST() {
        boolean[] inMST = new boolean[vertices];
        int[] key = new int[vertices];
        int[] parent = new int[vertices];

        // Initialize arrays
        Arrays.fill(inMST, false);
        Arrays.fill(key, Integer.MAX_VALUE); // Use Integer.MAX_VALUE instead of a custom large value
        Arrays.fill(parent, -1);

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

    private int minKey(int[] key, boolean[] inMST) {
        int min = Integer.MAX_VALUE; // Use Integer.MAX_VALUE instead of a custom large value
        int minIndex = -1;

        for (int v = 0; v < vertices; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    private void printMST(int[] parent) {
        System.out.println("Edge \tWeight");
        for (int i = 1; i < vertices; i++) {
            System.out.println(parent[i] + " - " + i + "\t" + matrix[i][parent[i]]);
        }
    }
}

public class PrimAlgorithm {
    public static void main(String[] args) {
        Graph graph = new Graph(5);

        graph.addEdge(0, 1, 2);
        graph.addEdge(0, 3, 6);
        graph.addEdge(1, 2, 3);
        graph.addEdge(1, 3, 8);
        graph.addEdge(1, 4, 5);
        graph.addEdge(2, 4, 7);
        graph.addEdge(3, 4, 9);

        graph.primMST();
    }
}
