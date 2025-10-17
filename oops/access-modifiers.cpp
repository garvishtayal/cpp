#include <iostream>
using namespace std;

class Base {
public:
    int pub = 1;
protected:
    int prot = 2;
private:
    int priv = 3;
};

class Derived : public Base {
public:
    void show() {
        cout << "pub = " << pub << endl;     // accessible
        cout << "prot = " << prot << endl;   // accessible
        // cout << "priv = " << priv << endl; // Error: private, not accessible
    }
};

int main() {
    Derived d;
    cout << d.pub << endl;    // OK
    // cout << d.prot << endl; // Error
    // cout << d.priv << endl; // Error
    d.show();                 // prints pub and prot
}
