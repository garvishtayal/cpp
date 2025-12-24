#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void printDescending(int n) {
    if (n == 1) {         // Base case
        cout << 1 << " " << endl;
        return;
    }
    cout << n << " " << endl;;
    this_thread::sleep_for(chrono::seconds(1));
    printDescending(n - 1);
}

int main() {
    int n;
    cin >> n;
    printDescending(n);
    return 0;
}
