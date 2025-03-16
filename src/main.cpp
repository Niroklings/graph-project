#include "Graph.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  try {
    Graph g("../graph.txt");

    auto distances = g.shortestDistances();

    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < distances.size(); ++i) {
      vec.emplace_back(i, distances[i]);
    }

    for (const auto &pair : vec) {
      if (pair.second == -1) {
        std::cout << "Отсутсвует путь" << std::endl;
      } else {
        std::cout << pair.second << std::endl;
      }
    }
  } catch (const std::exception &e) {
    std::cerr << "Ошибка: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
