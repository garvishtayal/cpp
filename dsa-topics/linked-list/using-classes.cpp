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
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    // ---------- push_back ----------
    // Adds a node at the end
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    // ---------- insert ----------
    // Inserts a node at given position (0-based index)
    void insert(int pos, int val) {
        // insert at head
        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;

        // move to (pos-1)th node
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        // invalid position
        if (temp == NULL) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        // if inserted at end, update tail
        if (newNode->next == NULL)
            tail = newNode;
    }

    // ---------- search ----------
    // Searches value in linked list
    // Returns true if found, else false
    bool search(int key) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }

        return false;
    }

    // ---------- pop_front ----------
    void pop_front() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL)
            tail = NULL;
    }

    // ---------- pop_back ----------
    void pop_back() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
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

    ll.insert(2, 10);   // insert at index 2

    ll.pop_front();
    ll.pop_back();

    ll.printLL();

    // search demo
    if (ll.search(10))
        cout << "10 found\n";
    else
        cout << "10 not found\n";

    return 0;
}
