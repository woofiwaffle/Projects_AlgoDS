#ifndef PROJECTS_ALGODS_BINARYTREE_H
#define PROJECTS_ALGODS_BINARYTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {};
};


class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    void parseTree(const string& expression);
    void printBinaryTree();
    void createBinaryTreeFromFile(const string& filename);
    void bypassDirect();

    void array(BinaryTreeNode* root, vector<int>& arrayNum);
    [[nodiscard]] BinaryTreeNode* getRoot() const;

private:
    BinaryTreeNode* root;

    void deleteBinaryTree(BinaryTreeNode* tree);
    BinaryTreeNode* parseExpression(const string& expression, size_t& pos);
    void printBinaryTree(BinaryTreeNode* tree, string indent, bool isLeft);
    void bypassDirect(BinaryTreeNode* tree);
};


#endif //PROJECTS_ALGODS_BINARYTREE_H