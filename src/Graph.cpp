#include "Graph.h"
#include <fstream>
#include <queue>
#include <sstream>
#include <stdexcept>

Graph::Graph(const std::string &filename) { loadGraphFromFile(filename); }

void Graph::loadGraphFromFile(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::invalid_argument("Не удалось открыть файл.");
  }

  std::string line;
  int lineNumber = 0;
  std::getline(file, line);
  lineNumber++;
  std::istringstream is(line);
  if (!(is >> numVertices) || is.rdbuf()->in_avail() != 0) {
    throw std::invalid_argument("Некорректная строка " +
                                std::to_string(lineNumber) + ": " + line +
                                "\nПроверьте наличие лишних символов.");
  } else if (numVertices <= 0) {
    throw std::invalid_argument("Некорректное количество вершин.");
  }

  int numEdges;
  std::getline(file, line);
  lineNumber++;
  std::istringstream iss(line);
  if (!(iss >> numEdges) || iss.rdbuf()->in_avail() != 0) {
    throw std::invalid_argument("Некорректная строка " +
                                std::to_string(lineNumber) + ": " + line +
                                "\nПроверьте наличие лишних символов.");
  } else if (numEdges < 0) {
    throw std::invalid_argument("Некорректное количество рёбер.");
  }

  adj.clear();
  adj.resize(numVertices);

  for (int i = 0; i < numEdges; ++i) {
    if (!std::getline(file, line)) {
      throw std::invalid_argument("Недостаточно данных для рёбер.");
    }
    lineNumber++;
    std::istringstream edgeStream(line);
    int u, v;
    if (!(edgeStream >> u >> v) || edgeStream.rdbuf()->in_avail() != 0) {
      throw std::invalid_argument("Некорректная строка " +
                                  std::to_string(lineNumber) + ": " + line +
                                  "\nПроверьте наличие лишних символов.");
    } else if (u < 0 || v < 0 || u >= numVertices || v >= numVertices) {
      throw std::invalid_argument("Некорректное ребро: " + line);
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  std::getline(file, line);
  lineNumber++;
  std::istringstream isss(line);
  if (!(isss >> startVertex) || isss.rdbuf()->in_avail() != 0) {
    throw std::invalid_argument("Некорректная строка " +
                                std::to_string(lineNumber) + ": " + line +
                                "\nПроверьте наличие лишних символов.");
  } else if (startVertex < 0 || startVertex >= numVertices) {
    throw std::invalid_argument("Некорректное количество рёбер.");
  }

  if (std::getline(file, line)) {
    throw std::invalid_argument("Некорректный файл.");
  }
}

std::vector<int> Graph::shortestDistances() const {
  std::vector<int> distances(numVertices, -1);
  std::queue<int> q;

  distances[startVertex] = 0;
  q.push(startVertex);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    int currentDistance = distances[node];

    for (int neighbor : adj[node]) {
      if (distances[neighbor] == -1) {
        distances[neighbor] = currentDistance + 1;
        q.push(neighbor);
      }
    }
  }

  return distances;
}
