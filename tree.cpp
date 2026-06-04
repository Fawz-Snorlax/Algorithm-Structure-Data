#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createEmpty() {
    return nullptr;
}

Node* allocation(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void deallocation(Node* tree) {delete tree;}

Node* insert(Node* tree, int data) {
    if (tree == nullptr) tree = allocation(data);
    else if (data <= tree->data) tree->left = insert(tree->left, data);
    else tree->right = insert(tree->right, data);

    return tree;
}

// Tree Condition
bool isTreeEmpty(Node* tree) {return tree == nullptr;}
bool isOneElement(Node* tree) {return (tree != nullptr && tree->left == nullptr && tree->right == nullptr);}
bool isUnerLeft(Node* tree) {return (tree != nullptr && tree->left != nullptr && tree->right == nullptr);}
bool isUnerRight(Node* tree) {return (tree != nullptr && tree->left == nullptr && tree->right != nullptr);}

// Traversal
void preOrder(Node* tree) {
    if (isTreeEmpty(tree)) return;
    cout << tree->data << " ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(Node* tree) {
    if (isTreeEmpty(tree)) return;
    inOrder(tree->left);
    cout << tree->data << " ";
    inOrder(tree->right);
}

void postOrder(Node* tree) {
    if (isTreeEmpty(tree)) return;
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->data << " ";
}

// Skew
bool isSkewLeft(Node* tree) {
    if (tree == nullptr) return true;
    if (isUnerLeft(tree)) return isSkewLeft(tree->left);
    return false;
}

bool isSkewRight(Node* tree) {
    if (tree == nullptr) return true;
    if (isUnerRight(tree)) return isSkewRight(tree->right);
    return false;
}

int countNode(Node* tree) {
    if (isTreeEmpty(tree)) return 0;
    return 1 + countNode(tree->left) + countNode(tree->right); 
}

int countLeaves(Node* tree) {
    if (isTreeEmpty(tree)) return 0;
    if (isOneElement(tree)) return 1;
    return countLeaves(tree->left) + countLeaves(tree->right);
}

int level(Node* tree, int data, int lv = 1) {
    if (isTreeEmpty(tree)) return 0;
    if (data == tree->data) return lv;
    int levelLeft = level(tree->left, data, lv+1);
    int levelRight = level(tree->right, data, lv+1);
    if (levelLeft != 0) return levelLeft;
    return levelRight;
}

bool searchTree(Node* tree, int data) {
    if (isTreeEmpty(tree)) return false;
    if (data == tree->data) return true;
    return (searchTree(tree->left, data) || searchTree(tree->right, data));
}

bool searchLeaf(Node* tree, int data) {
    if (isTreeEmpty(tree)) return false;
    if (isOneElement(tree)) return tree->data == data;
    if (isUnerLeft(tree)) return searchLeaf(tree->left, data);
    if (isUnerRight(tree)) return searchLeaf(tree->right, data);
    return searchLeaf(tree->left, data) || searchLeaf(tree->right, data);
}

int main() {
    Node* Tree = createEmpty();
//          5
//       /     \
//      3       8
//     / \     / \
//    2   4   6   9
//   /             \
//  1              11
//                 /
//                10
    Tree = insert(Tree, 5);
    Tree = insert(Tree, 8);
    Tree = insert(Tree, 3);
    Tree = insert(Tree, 9);
    Tree = insert(Tree, 6);
    Tree = insert(Tree, 2);
    Tree = insert(Tree, 4);
    Tree = insert(Tree, 11);
    Tree = insert(Tree, 10);
    Tree = insert(Tree, 1);

    cout << "Pre-Order: "; preOrder(Tree); cout << endl;
    cout << "In-Order: "; inOrder(Tree); cout << endl;
    cout << "Post-Order: "; postOrder(Tree); cout << endl;

    return 0;
}
