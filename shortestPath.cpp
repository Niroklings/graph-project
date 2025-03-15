#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <sstream>

using namespace std;

class Graph {
public:
    Graph(int vertices) : adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> shortestDistances(int start) {
        vector<int> distances(adj.size(), numeric_limits<int>::max());
        queue<int> q;

        distances[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (distances[neighbor] == numeric_limits<int>::max()) {
                    distances[neighbor] = distances[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        return distances;
    }

private:
    vector<vector<int>> adj;
};

bool isValidEdge(int u, int v, int vertices) {
    return u >= 0 && u < vertices && v >= 0 && v < vertices;
}

bool isValidStartVertex(int start, int vertices) {
    return start >= 0 && start < vertices;
}

int main() {
    ifstream input("graph.txt");
    if (!input) {
        cerr << "Error opening file!\n";
        return 1;
    }

    int vertices, edges;
    input >> vertices >> edges;

    Graph graph(vertices);

    for (int i = 0; i < edges; ++i) {
        int u, v;
        input >> u >> v;

        graph.addEdge(u, v);
    }

    int startVertex;
    input >> startVertex;

    input.close();

    vector<int> distances = graph.shortestDistances(startVertex);

    for (int i = 0; i < vertices; ++i) {
            cout << distances[i] << "\n";
    }

    return 0;
}
