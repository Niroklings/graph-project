#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>

class Graph {
public:
    Graph(const std::string& filename);

    std::unordered_map<int, int> shortestDistances() const;

private:
    int numVertices; 
    std::unordered_map<int, std::vector<int>> adj;
    int startVertex;

    void loadGraphFromFile(const std::string& filename);
};

#endif // GRAPH_H
