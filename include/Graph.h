#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
public:
    Graph(const std::string& filename);

    std::vector<int> shortestDistances() const;  

private:
    int numVertices; 
    std::vector<std::vector<int>> adj;
    int startVertex;

    void loadGraphFromFile(const std::string& filename);
};

#endif // GRAPH_H
