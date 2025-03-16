#include "Graph.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <queue>

Graph::Graph(const std::string& filename) {
    loadGraphFromFile(filename);
}

void Graph::loadGraphFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Не удалось открыть файл.");
    }

    std::string line;
    if (!std::getline(file, line) || !(std::istringstream(line) >> numVertices) || numVertices <= 0) {
        throw std::invalid_argument("Некорректное количество вершин.");
    }

    int numEdges;
    if (!std::getline(file, line) || !(std::istringstream(line) >> numEdges) || numEdges < 0) {
        throw std::invalid_argument("Некорректное количество рёбер.");
    }

    adj.clear();

    for (int i = 0; i < numEdges; ++i) {
        if (!std::getline(file, line)) {
            throw std::invalid_argument("Недостаточно данных для рёбер.");
        }
        std::istringstream edgeStream(line);
        int u, v;
        if (!(edgeStream >> u >> v) || u < 0 || v < 0 || u >= numVertices || v >= numVertices) {
            throw std::invalid_argument("Некорректное ребро: " + line);
        }
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    if (!std::getline(file, line) || !(std::istringstream(line) >> startVertex) || startVertex < 0 || startVertex >= numVertices) {
        throw std::invalid_argument("Некорректная начальная вершина.");
    }
}

std::unordered_map<int, int> Graph::shortestDistances() const {
    std::unordered_map<int, int> distances;
    std::queue<int> q;

    for (int i = 0; i < numVertices; ++i) {
        distances[i] = -1; 
    }
    distances[startVertex] = 0;
    q.push(startVertex);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        int currentDistance = distances[node];

        for (int neighbor : adj.at(node)) {
            if (distances[neighbor] == -1) { 
                distances[neighbor] = currentDistance + 1;
                q.push(neighbor);
            }
        }
    }

    return distances;
}
