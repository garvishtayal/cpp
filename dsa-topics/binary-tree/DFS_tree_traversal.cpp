// tree_traversals.cpp
// DFS Traversals using recursion
// Preorder:  Root -> Left -> Right
// Inorder:   Left -> Root -> Right
// Postorder: Left -> Right -> Root

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorder(Node* r) {
    if (!r) return;
    cout << r->val << " ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->val << " ";
    inorder(r->right);
}

void postorder(Node* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->val << " ";
}

int main() {
    // Tree:
    //      1
    //     / \
    //    2   3
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Preorder: ";  preorder(root);   cout << "\n";
    cout << "Inorder: ";   inorder(root);    cout << "\n";
    cout << "Postorder: "; postorder(root);  cout << "\n";

    return 0;
}
