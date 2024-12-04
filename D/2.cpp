#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Helper function for DFS
    void countPathsUtil(int u, int d, int& pathCount) {
        // If the current vertex is the destination, increment the path count
        if (u == d) {
            pathCount++;
            return;
        }

        // Recur for all the vertices adjacent to this vertex
        for (int i : adj[u]) {
            countPathsUtil(i, d, pathCount);
        }
    }

    // Function to count all paths from source to destination
    int countPaths(int source, int destination) {
        int pathCount = 0; // Initialize path count
        countPathsUtil(source, destination, pathCount);
        return pathCount;
    }
};

int main() {
    // Create a graph based on the image
    Graph g(5); // 5 vertices (A, B, C, D, E)

    // Add edges as per the graph in the image
    g.addEdge(0, 1); // A -> B
    g.addEdge(0, 2); // A -> C
    g.addEdge(0, 3); // A -> D
    g.addEdge(1, 4); // B -> E
    g.addEdge(2, 1); // C -> B
    g.addEdge(2, 3); // C -> D
    g.addEdge(3, 4); // D -> E

    // Input test cases
    int source = 0, destination = 4; // A -> E
    cout << "Total paths from A to E: " << g.countPaths(source, destination) << endl;

    source = 0, destination = 2; // A -> C
    cout << "Total paths from A to C: " << g.countPaths(source, destination) << endl;

    return 0;
}
