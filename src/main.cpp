#include "Graph.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

int main() {
    try {
        Graph g("../graph.txt");

        auto distances = g.shortestDistances();

        std::vector<std::pair<int, int>> vec;
        for (int i = 0; i < distances.size(); ++i) {
            vec.emplace_back(i, distances[i]);
        }

        for (const auto& pair : vec) {
            std::cout << pair.second << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
