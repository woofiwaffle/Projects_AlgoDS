#include "AVLTree.h"


AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    deleteTree(root);
}



int AVLTree::getHeight(AVLTreeNode* tree) {
    if(tree == nullptr){
        return 0;
    }
    return tree->height;
}



int AVLTree::getBalance(AVLTreeNode* tree) {
    if(tree == nullptr){
        return 0;
    }
    return getHeight(tree->left) - getHeight(tree->right);
}



AVLTreeNode* AVLTree::rotateRight(AVLTreeNode* y) {
    AVLTreeNode* x = y->left;
    AVLTreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}



AVLTreeNode* AVLTree::rotateLeft(AVLTreeNode* x) {
    AVLTreeNode* y = x->right;
    AVLTreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
}



void AVLTree::insert(int key) {
    root = insert(root, key);
}



AVLTreeNode* AVLTree::insert(AVLTreeNode* root, int key) {
    if(root == nullptr){
        return new AVLTreeNode(key);
    }

    if(key < root->data) {
        root->left = insert(root->left, key);
    }
    else if(key > root->data){
        root->right = insert(root->right, key);
    }
    else{
        return root;
    }

    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if(balance > 1 && key < root->left->data){
        return rotateRight(root);
    }
    if(balance < -1 && key > root->right->data){
        return rotateLeft(root);
    }
    if(balance > 1 && key > root->left->data){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if(balance < -1 && key < root->right->data){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}



void AVLTree::printAVLTree() {
    if(root == nullptr){
        cout << "Empty tree" << endl;
    }
    else{
        printAVLTree(root, "", false);
    }
}



void AVLTree::printAVLTree(AVLTreeNode* root, string indent, bool isLeft) {
    if(root != nullptr){
        printAVLTree(root->right, indent + (isLeft ? "   " : "   "), false);

        cout << indent;

        if(isLeft){
            cout << "L--> ";
        }
        else{
            cout << "R--> ";
        }
        cout << root->data << endl;
        printAVLTree(root->left, indent + (isLeft ? "   " : "   "), true);
    }
}



void AVLTree::remove(int key) {
    root = remove(root, key);
}



AVLTreeNode* AVLTree::remove(AVLTreeNode* tree, int key) {
    if(tree == nullptr){
        return nullptr;
    }

    if(key < tree->data){
        tree->left = remove(tree->left, key);
    }
    else if(key > tree->data){
        tree->right = remove(tree->right, key);
    }
    else{
        if(tree->left == nullptr || tree->right == nullptr){
            AVLTreeNode* temp = (tree->left != nullptr) ? tree->left : tree->right;

            if(temp == nullptr){
                temp = tree;
                tree = nullptr;
            }
            else{
                *tree = *temp;
            }

            delete temp;
        }
        else{
            AVLTreeNode* temp = minValue(tree->right);

            tree->data = temp->data;
            tree->right = remove(tree->right, temp->data);
        }
    }

    if(tree == nullptr){
        return nullptr;
    }

    int balance = getBalance(tree);

    if(balance > 1 && getBalance(tree->left) >= 0){
        return rotateRight(tree);
    }
    if(balance > 1 && getBalance(tree->left) < 0){
        tree->left = rotateLeft(tree->left);
        return rotateRight(tree);
    }
    if(balance < -1 && key > getBalance(tree->right) <= 0){
        return rotateLeft(tree);
    }
    if(balance < -1 && key < getBalance(tree->right) > 0){
        tree->right = rotateRight(tree->right);
        return rotateLeft(tree);
    }

    return tree;
}



AVLTreeNode* AVLTree::minValue(AVLTreeNode* tree) {
    AVLTreeNode* current = tree;

    while(current->left != nullptr){
        current = current->left;
    }

    return current;
}



bool AVLTree::search(int key) {
    return search(root, key);
}



bool AVLTree::search(AVLTreeNode* tree, int key) {
    if(tree == nullptr){
        return false;
    }

    if(key == tree->data){
        return true;
    }

    if(key < tree->data){
        return search(tree->left, key);
    }
    else{
        return search(tree->right, key);
    }
}



void AVLTree::bypassInChange() {
    bypassInChange(root);
    cout << endl;
}



void AVLTree::bypassInChange(AVLTreeNode* tree) {
    if(tree == nullptr){
        return;
    }

    queue<AVLTreeNode*> q;
    q.push(tree);

    while(!q.empty()){
        AVLTreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if(current->left != nullptr){
            q.push(current->left);
        }

        if(current->right != nullptr){
            q.push(current->right);
        }
    }
}



void AVLTree::bypassDirect() {
    bypassDirect(root);
    cout << endl;
}



void AVLTree::bypassDirect(AVLTreeNode* tree) {
    if(tree != nullptr){
        cout << tree->data << " ";
        bypassDirect(tree->left);
        bypassDirect(tree->right);
    }
}



void AVLTree::bypassReverse() {
    bypassReverse(root);
    cout << endl;
}



void AVLTree::bypassReverse(AVLTreeNode *tree) {
    if(tree != nullptr){
        bypassReverse(tree->left);
        bypassReverse(tree->right);
        cout << tree->data << " ";
    }
}



void AVLTree::bypassSymmetrical() {
    bypassSymmetrical(root);
    cout << endl;
}



void AVLTree::bypassSymmetrical(AVLTreeNode* tree) {
    if(tree != nullptr){
        bypassSymmetrical(tree->left);
        cout << tree->data << " ";
        bypassSymmetrical(tree->right);
    }
}



void AVLTree::deleteTree(AVLTreeNode* tree){
    if(tree != nullptr){
        deleteTree(tree->left);
        deleteTree(tree->right);
        delete tree;
    }
}



void AVLTree::clearAVLTree() {
    clearAVLTree(root);
    root = nullptr;
}



void AVLTree::clearAVLTree(AVLTreeNode* root) {
    if(root != nullptr){
        clearAVLTree(root->left);
        clearAVLTree(root->right);
        delete root;
    }
}