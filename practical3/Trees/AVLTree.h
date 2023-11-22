#ifndef PROJECTS_ALGODS_AVLTREE_H
#define PROJECTS_ALGODS_AVLTREE_H

#include <iostream>
#include <queue>

using namespace std;

struct AVLTreeNode {
    int data;
    AVLTreeNode* left;
    AVLTreeNode* right;
    int height;

    AVLTreeNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};


class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void printAVLTree();

    void insert(int key);
    void remove(int key);
    bool search(int key);

    void bypassInChange();
    void bypassDirect();
    void bypassReverse();
    void bypassSymmetrical();

    void clearAVLTree();

private:
    AVLTreeNode* root;

    int getHeight(AVLTreeNode* tree);
    int getBalance(AVLTreeNode* tree);

    AVLTreeNode* rotateRight(AVLTreeNode* y);
    AVLTreeNode* rotateLeft(AVLTreeNode* x);

    AVLTreeNode* minValue(AVLTreeNode* tree);

    void printAVLTree(AVLTreeNode* root, string indent, bool isLeft);

    AVLTreeNode* insert(AVLTreeNode* root, int key);
    AVLTreeNode* remove(AVLTreeNode* tree, int key);
    bool search(AVLTreeNode* tree, int key);

    void bypassInChange(AVLTreeNode* tree);
    void bypassDirect(AVLTreeNode* tree);
    void bypassReverse(AVLTreeNode* tree);
    void bypassSymmetrical(AVLTreeNode* tree);

    void deleteTree(AVLTreeNode* tree);
    void clearAVLTree(AVLTreeNode* root);
};


#endif //PROJECTS_ALGODS_AVLTREE_H