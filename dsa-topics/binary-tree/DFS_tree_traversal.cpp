// tree_traversals.cpp
// DFS Traversals using recursion
//
// Tree used:
//        1
//       / \
//      2   3
//
// Preorder  (Root → Left → Right):   1 2 3
// Inorder   (Left → Root → Right):   2 1 3
// Postorder (Left → Right → Root):   2 3 1

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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Preorder: ";   // Output: 1 2 3
    preorder(root);
    cout << "\n";

    cout << "Inorder: ";    // Output: 2 1 3
    inorder(root);
    cout << "\n";

    cout << "Postorder: ";  // Output: 2 3 1
    postorder(root);
    cout << "\n";

    return 0;
}
