#include <iostream>
using namespace std;

void printDescending(int n) {
    if (n == 1) {         // Base case
        cout << 1 << " ";
        return;
    }
    cout << n << " ";
    printDescending(n - 1);
}

int main() {
    int n;
    cin >> n;
    printDescending(n);
    return 0;
}
