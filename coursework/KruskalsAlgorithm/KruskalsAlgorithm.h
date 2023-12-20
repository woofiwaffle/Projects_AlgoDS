#ifndef PROJECTS_ALGODS_KRUSKALSALGORITHM_H
#define PROJECTS_ALGODS_KRUSKALSALGORITHM_H

#include <iostream>
#include <vector>                        // сложность: O(E log V) - E - количество ребер V - количество вершин
#include <algorithm>                     // обход в глубину - проходит по всем потомкам одной вершины
#include <fstream>                       // обход в ширину - проходит по всем соседям вершины
#include <sstream>                       // список смежности - каждая вершина представляет собой список своих соседей
                                         //
using namespace std;                     // матрица смежности - в виде двумерной матрица, где M[i][j] - вес ребра между
                                         // i и j
struct Edge {                            // матрица идентичности - в виде матрицы, где строки представляют вершины, а
    string vertex1;                      // столбцы - ребра
    string vertex2;
    int weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};


class KruskalsAlgorithm {
public:
    explicit KruskalsAlgorithm(const string& inputFile, const string& outputFile);

    void sortEdges();
    void kruskal();

    void outputInFile();

private:
    vector<int> parent; // каждой вершине присваивается корень
    vector<int> vertexRank; // инициализируются ранги вершин
    vector<string> vertices; // добавляются вершины
    vector<Edge> edgeList;   // ненулевые веса
    vector<Edge> minSpanTree;

    string outputFile;

    void initDSU();
    int findRoot(int root);
    void unite(int root1, int root2);
};

#endif //PROJECTS_ALGODS_KRUSKALSALGORITHM_H