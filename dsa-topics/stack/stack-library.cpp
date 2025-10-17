#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30
    cout << "Size: " << s.size() << endl;       // 3

    s.pop();  // removes 30
    cout << "After pop, top: " << s.top() << endl; // 20

    // Empty the stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
