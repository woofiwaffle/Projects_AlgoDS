#include "BinaryTree.h"


BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    deleteBinaryTree(root);
}



void BinaryTree::parseTree(const string& expression) {
    size_t pos = 0;
    root = parseExpression(expression, pos);
}



BinaryTreeNode* BinaryTree::parseExpression(const string& expression, size_t& pos) {
    if(expression.empty()){
        cerr << "Error: Expression is empty\n" << endl;
        return nullptr;
    }

    if(pos >= expression.size() || expression[pos] == ')'){
        pos++;
        return nullptr;
    }

    while(pos < expression.size() && isspace(expression[pos])){
        pos++;
    }
    if(expression[pos] == '(') {
        pos++;

        while(pos < expression.size() && isspace(expression[pos])){
            pos++;
        }
        if(!isdigit(expression[pos]) && expression[pos] != '-'){
            cerr << "Error: Expected a digit or '-' after '('\n" << endl;
            return nullptr;
        }
        int value = 0;
        int sign = 1;

        if(expression[pos] == '-'){
            sign = -1;
            pos++;
        }
        while(isdigit(expression[pos])){
            value = value * 10 + (expression[pos] - '0');
            pos++;
        }

        BinaryTreeNode* tree = new BinaryTreeNode(sign * value);

        while(pos < expression.size() && isspace(expression[pos])){
            pos++;
        }

        stack<BinaryTreeNode*> treeStack;
        treeStack.push(tree);

        while(!treeStack.empty()){
            while(pos < expression.size() && isspace(expression[pos])){
                pos++;
            }
            if(expression[pos] == '('){
                pos++;

                while(pos < expression.size() && isspace(expression[pos])){
                    pos++;
                }
                if(!isdigit(expression[pos]) && expression[pos] != '-'){
                    cerr << "Error: Expected a digit or '-' after '('\n" << endl;
                    return nullptr;
                }

                int value = 0;
                int sign = 1;

                if(expression[pos] == '-'){
                    sign = -1;
                    pos++;
                }
                while(isdigit(expression[pos])){
                    value = value * 10 + (expression[pos] - '0');
                    pos++;
                }
                sign *= value;
                BinaryTreeNode* newTree = new BinaryTreeNode(sign);
                BinaryTreeNode* currentTree = treeStack.top();

                if(!currentTree->left){
                    currentTree->left = newTree;
                }
                else{
                    currentTree->right = newTree;
                }
                treeStack.push(newTree);
            }
            else if(expression[pos] == ')'){
                pos++;
                treeStack.pop();
            }
            else{
                cerr << "Error: Unexpected character '" << expression[pos] << "'" << endl;
                return nullptr;
            }
        }
        return tree;
    }
    cerr << "Error: Unexpected character '" << expression[pos] << "'" << endl;
    return nullptr;
}



void BinaryTree::printBinaryTree() {
    if(root == nullptr){
        cout << "Empty tree" << endl;
    }
    else{
        printBinaryTree(root, "", false);
    }
}



void BinaryTree::printBinaryTree(BinaryTreeNode* tree, string indent, bool isLeft) {
    if(tree != nullptr){
        printBinaryTree(tree->right, indent + (isLeft ? "   " : "   "), false);

        cout << indent;

        if(isLeft){
            cout << "L--> ";
        }
        else{
            cout << "R--> ";
        }
        cout << tree->data << endl;
        printBinaryTree(tree->left, indent + (isLeft ? "   " : "   "), true);
    }
}



void BinaryTree::createBinaryTreeFromFile(const std::string& filename) {
    ifstream file(filename);

    if(!file.is_open()){
        cout << "Unable to open the file" << endl;
    }
    string expression;
    getline(file, expression);

    if(expression.empty()){
        cout << "File is empty" << endl;
    }
    file.close();

    size_t pos = 0;
    root = parseExpression(expression, pos);

    if(root){
        cout << "Tree successfully created from file\n" << endl;
    }
    else{
        cout << "Failed to created tree from file\n" << endl;
    }
}



void BinaryTree::bypassDirect() {
    bypassDirect(root);
    cout << endl;
}



void BinaryTree::bypassDirect(BinaryTreeNode* tree) {
    if(tree != nullptr){
        cout << tree->data << " ";
        bypassDirect(tree->left);
        bypassDirect(tree->right);
    }
}



void BinaryTree::deleteBinaryTree(BinaryTreeNode* tree) {
    if(tree != nullptr){
        deleteBinaryTree(tree->left);
        deleteBinaryTree(tree->right);
        delete tree;
    }
}



void BinaryTree::array(BinaryTreeNode* root, vector<int>& arrayNum) {
    if(root != nullptr){
        arrayNum.push_back(root->data);
        array(root->left, arrayNum);
        array(root->right, arrayNum);
    }
}



BinaryTreeNode* BinaryTree::getRoot() const {
    return root;
}