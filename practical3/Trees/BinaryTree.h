#ifndef PROJECTS_ALGODS_BINARYTREE_H
#define PROJECTS_ALGODS_BINARYTREE_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

class BinaryTree {
public:
    struct BinTree {
        int key;
        BinTree* left;
        BinTree* right;

        BinTree(int value){
            key = value;
            left = nullptr;
            right = nullptr;
        }
    };

    BinTree* insertNode(BinTree* root, int value);
    BinTree* createTree(const vector<int>& array);
    BinTree searchNode(BinTree* root, int value);
    BinTree* findMinimum(BinTree* node);
    BinTree* deleteNode(BinTree* root, int value);
    void printBinaryTree(BinTree* root, string indent = "", bool isleft = false);
    void writeBinaryTree(BinTree* root, ofstream& outFile, string indent, bool isLeft);
    void writeOperations(BinTree* root, const string& filename, int insertedValue, int deletedValue, int searchValue);
    void bypassDirect(BinTree* root);
    void bypassReverse(BinTree* root);
    void bypassSymmetrical(BinTree* root);
};


#endif //PROJECTS_ALGODS_BINARYTREE_H
