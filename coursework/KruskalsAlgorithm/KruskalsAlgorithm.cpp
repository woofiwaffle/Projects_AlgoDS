#include "KruskalsAlgorithm.h"



KruskalsAlgorithm::KruskalsAlgorithm(const string& inputFile, const string& outputFile)
                                    : outputFile(outputFile) {
    ifstream filename;

    filename.open(inputFile);
    if(!filename.is_open()){
        cerr << "Input File doesn't open" << endl;
    }

    string line;
    getline(filename, line);
    istringstream edgeStream(line);

    cout << "Original graph:" << endl;
    string vertex;
    while(edgeStream >> vertex){
        cout << vertex << " ";
        vertices.push_back(vertex);
    }
    cout << endl;

    initDSU();

    for(size_t i = 0; i < vertices.size(); ++i){
        for(size_t j = 0; j < vertices.size(); ++j){
            int weight;
            filename >> weight;
            cout << weight << " ";
            if(i < j && weight > 0){
                Edge edge;
                edge.vertex1 = vertices[i];
                edge.vertex2 = vertices[j];
                edge.weight = weight;
                edgeList.push_back(edge);
            }
        }
        cout << endl;
    }
    filename.close();
}



void KruskalsAlgorithm::initDSU() {       // создание отдельного множества для каждой вершины
    parent.resize(vertices.size());
    vertexRank.assign(vertices.size(), 1);

    for(int i = 0; i < vertices.size(); ++i){
        parent[i] = i;
    }
}



void KruskalsAlgorithm::sortEdges() {          // ребра сортируются в порядке возрастания веса
    std::sort(edgeList.begin(), edgeList.end());
}



void KruskalsAlgorithm::kruskal() {
    for(const Edge& edge : edgeList){
        auto iter1 = std::find(vertices.begin(), vertices.end(), edge.vertex1);
        auto iter2 = std::find(vertices.begin(), vertices.end(), edge.vertex2);

        if(findRoot(std::distance(vertices.begin(), iter1)) != findRoot(std::distance(vertices.begin(), iter2))){
            minSpanTree.push_back(edge);  // если ребро не образуется цикл, оно добавляется в minSpanTree
            unite(std::distance(vertices.begin(), iter1), std::distance(vertices.begin(), iter2));
        }
    }
}



int KruskalsAlgorithm::findRoot(int root) { // рекурсивная функция поиска корня множества
    if(parent[root] == root){
        return root;
    }
    return parent[root] = findRoot(parent[root]);
}



void KruskalsAlgorithm::unite(int root1, int root2) {   // объединение двух множеств по рангу
    int rootX = findRoot(root1);
    int rootY = findRoot(root2);

    if(rootX != rootY){
        if(vertexRank[rootX] < vertexRank[rootY]){
            std::swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        vertexRank[rootX] += vertexRank[rootY];
    }
}



void KruskalsAlgorithm::outputInFile() {
    ofstream outFile(outputFile);
    if(!outFile.is_open()){
        cerr << "Output File doesn't open" << endl;
    }

    cout << "\nMinimum Spanning Tree:" << endl;
    outFile << "Minimum Spanning Tree:" << endl;

    for(const Edge& edge : minSpanTree){
        cout << edge.vertex1 << " " << edge.vertex2 << endl;
        outFile << edge.vertex1 << " " << edge.vertex2 << endl;
    }

    int totalWeight = 0;
    for(const Edge& edge : minSpanTree){
        totalWeight += edge.weight;
    }
    cout << "\nTotal weight: ";
    cout << totalWeight << endl;

    outFile << "Total weight: ";
    outFile << totalWeight << endl;
}