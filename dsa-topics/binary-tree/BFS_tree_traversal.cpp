// Level Order Traversal (BFS)
// 1) Normal LOT  -> prints in one line
// 2) Level-wise -> prints each level in new line (NULL marker)

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// 1️⃣ Simple Level Order (one line)
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << curr->data << " ";

        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

// 2️⃣ Level Order with new line per level
void levelOrderByLine(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);   // marker for end of level

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        if (curr == NULL) {
            cout << endl;          // level finished
            if (!q.empty()) q.push(NULL);
            continue;
        }

        cout << curr->data << " ";

        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    // Tree:
    //        1
    //      /   \
    //     2     3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level Order: ";
    levelOrder(root);

    cout << "\n\nLevel Order by Level:\n";
    levelOrderByLine(root);

    return 0;
}
