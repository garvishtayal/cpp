#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    // --- STACK ---
    stack<int> st;
    st.push(10); st.push(20); st.push(30);
    cout << "Stack top: " << st.top() << endl; // 30
    st.pop();

    // --- QUEUE ---
    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    cout << "Queue front: " << q.front() << " back: " << q.back() << endl; // 1, 3
    q.pop();

    // --- PRIORITY QUEUE (MAX HEAP by default) ---
    priority_queue<int> pq;
    pq.push(5); pq.push(10); pq.push(2);
    cout << "Priority Queue top: " << pq.top() << endl; // 10
    pq.pop();

    // --- SET (sorted unique elements) ---
    set<int> s = {4, 1, 7, 1}; // duplicates ignored
    cout << "Set elements: ";
    for (int x : s) cout << x << " "; // 1 4 7
    cout << endl;

    // --- UNORDERED SET (unique elements, no order) ---
    unordered_set<int> us = {4, 1, 7, 1};
    cout << "Unordered Set elements: ";
    for (int x : us) cout << x << " ";
    cout << endl;

    // --- MAP (sorted key-value pairs) ---
    map<string, int> mp;
    mp["apple"] = 3; mp["banana"] = 5;
    cout << "Map[apple]: " << mp["apple"] << endl;

    // --- UNORDERED MAP (hashmap) ---
    unordered_map<string, int> ump;
    ump["dog"] = 2; ump["cat"] = 4;
    cout << "Unordered Map[cat]: " << ump["cat"] << endl;

    return 0;
}
