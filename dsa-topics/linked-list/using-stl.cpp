#include <bits/stdc++.h>
using namespace std;

/*
  STL provides a built-in doubly linked list called `list`.
  Header: <list>
  Namespace: std
*/

int main() {
    // ---------- Creating a linked list ----------
    list<int> ll;   // empty linked list

    // ---------- push_front ----------
    ll.push_front(1);   // 1
    ll.push_front(2);   // 2 -> 1
    ll.push_front(3);   // 3 -> 2 -> 1

    // ---------- push_back ----------
    ll.push_back(4);    // 3 -> 2 -> 1 -> 4
    ll.push_back(5);    // 3 -> 2 -> 1 -> 4 -> 5

    // ---------- pop_front ----------
    ll.pop_front();     // removes 3

    // ---------- pop_back ----------
    ll.pop_back();      // removes 5

    // ---------- Traversing the list ----------
    cout << "Linked List elements: ";
    for (int x : ll) {
        cout << x << " ";
    }
    cout << endl;

    // ---------- Size of list ----------
    cout << "Size: " << ll.size() << endl;

    // ---------- Front & Back ----------
    cout << "Front: " << ll.front() << endl;
    cout << "Back: " << ll.back() << endl;

    // ---------- Check empty ----------
    if (ll.empty())
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl;

    return 0;
}