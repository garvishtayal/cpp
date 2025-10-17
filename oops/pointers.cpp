#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* ptr = &a; //pointer of type int for a integer
    int** parentptr = &ptr; //pointer of type int pointer for ptr

    cout <<**(parentptr) <<endl; //derefrencing twice
}


//pass by reference

//-----through pointers

// changeA(&a);
void changeA(int* a) {
*a=20;
}

//-----through alias

// changeA(a);
void changeA(int &b) {
    b=20;
}
