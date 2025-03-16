# Название проекта: Алгоритм поиска кратчайших путей в графе

## Описание
Проект реализует структуру графа, который считывается из текстового файла. Алгоритм находит кратчайшие расстояния от заданной начальной вершины до всех остальных вершин с использованием поиска в ширину (BFS).

## Технологии
- Язык: C++
- Структуры данных: вектор
- Алгоритм: поиск в ширину (BFS)
- Инструмент для сборки: CMake
- Операционная система: Linux
- Тестирование: Google Test

## Формат входного файла
- Входной файл ``graph.txt`` формата:
```
N
M
u1 v1
u2 v2
...
uM vM
S
```
Где:
- N — количество вершин графа
- M — количество рёбер графа
- u v — пары вершин (от 0 до N-1), описывающие рёбра
- S — начальная вершина, с которой начинается поиск кратчайших путей

## Тестирование
В проекте используются юнит-тесты на базе Google Test. GoogleTest подключён как подмодуль Git.
Для подключения подмодюля:
git submodule update --init --recursive

## Сборка и запуск
```
mkdir build
cd build/
cmake ..
make
./main 
```
или ``./run_tests`` для запуска тестов

## Примечания
- Этот проект использует алгоритм поиска в ширину (BFS), который работает корректно только для невзвешенных графов.