#include <bits/stdc++.h>
using namespace std;

/*
priority_queue (Heap)

Default: MAX HEAP
Top element = largest element

Default: MAX HEAP
push  -> O(log n)
pop   -> O(log n)
top   -> O(1)
*/

int main() {

    // Max Heap
    priority_queue<int> maxH;
    maxH.push(10);
    maxH.push(30);
    maxH.push(20);
    cout << maxH.top() << endl; // 30
    maxH.pop();

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minH;
    minH.push(10);
    minH.push(30);
    minH.push(20);
    cout << minH.top() << endl; // 10

    return 0;
}
