// build_tree_preorder.cpp
// Build Binary Tree using Preorder (-1 = NULL)
// Uses recursion: Root -> Left -> Right

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* buildTree() {
    int x; 
    cin >> x;

    if (x == -1) return nullptr;     // base case

    Node* root = new Node(x);        // create root
    root->left = buildTree();        // build left subtree
    root->right = buildTree();       // build right subtree

    return root;
}

int main() {
    // Example input: 1 2 -1 -1 3 -1 -1
    Node* root = buildTree();
    return 0;
}
