#include <bits/stdc++.h>
using namespace std;

// ---------------- NODE CLASS ----------------
class Node {
public:
    int data;        // stores value
    Node* next;      // pointer to next node

    // constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// ---------------- LIST CLASS ----------------
class List {
private:
    Node* head;      // points to first node
    Node* tail;      // points to last node

public:
    // constructor
    List() {
        head = tail = NULL;   // empty list
    }

    // ---------- push_front ----------
    // Adds a node at the beginning
    void push_front(int val) {
        Node* newNode = new Node(val); // create node in heap

        // if list is empty
        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        // link new node to current head
        newNode->next = head;
        head = newNode; // update head
    }

    // ---------- push_back ----------
    // Adds a node at the end
    void push_back(int val) {
        Node* newNode = new Node(val);

        // if list is empty
        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode; // link last node
        tail = newNode;       // update tail
    }

    // ---------- pop_front ----------
    // Removes node from beginning
    void pop_front() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }

        Node* temp = head;    // store old head
        head = head->next;    // move head
        delete temp;          // free memory

        // if list becomes empty
        if (head == NULL)
            tail = NULL;
    }

    // ---------- pop_back ----------
    // Removes node from end
    void pop_back() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }

        // if only one node
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;

        // reach second last node
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;       // delete last node
        tail = temp;      // update tail
        tail->next = NULL;
    }

    // ---------- printLL ----------
    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ---------------- MAIN ----------------
int main() {
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(4);

    ll.pop_front();
    ll.pop_back();

    ll.printLL();

    return 0;
}