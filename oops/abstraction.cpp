#include <iostream>
using namespace std;

class Shape {          // Abstract class
public:
    virtual void draw() = 0;  // Pure virtual → makes class abstract
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle\n"; }
};

int main() {
    // Shape s;        // Error: abstract class
    Circle c;
    c.draw();           // Drawing Circle
}

//abstract class can only be made using pure virtual fn()s ( no other way or abstarct keyword )