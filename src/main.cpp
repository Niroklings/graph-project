#include "Graph.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

int main() {
    try {
        // Создание графа из файла
        Graph g("../graph.txt");

        // Вычисление кратчайших расстояний
        auto distances = g.shortestDistances();

        // Вывод расстояний
        std::vector<std::pair<int, int>> vec(distances.begin(), distances.end());
        for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
            std::cout << it->second << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
