#include <iostream>
using namespace std;

class Student {
public:
    string name;
    double cgpa;


    //normal contructor

    //normal constructor( unparameterized )
    Student() {
        cout << "I run without any parameter, just create the object" << endl;
    }

    //normal contructor( parameterized )
    Student(string n, double c) {
        this->name = n;
        this->cgpa = c;
        cout << "Normal constructor called\n";
    }


    //Copy Contructor

    //Deafult copy constructor
        //directly call s2(s1) ----will create a copy of s1 object named s2 in memory

    //custom copy constructor
    Student(const Student &s) {
        this->name = s.name;
        this->cgpa = s.cgpa;
        cout << "Custom Copy constructor called\n";
    }
};

int main() {

    //Student s1;  //normal constuctor ( unparameterized )

    Student s1("Garvish", 9.5); //normal constuctor ( parameterized )


    //Student s2(s1);  //custom copy constructor will run if defined, otherwise default copy constructor will run
}





//shallow and deep copy 
//----normal copy constructor makes shallow copy for deep copy :

// int main()
// {
//     int *onePtr = new int;
//     int *twoPtr = new int;

//     *onePtr = 5;
//     *twoPtr = 5;

//     cout << onePtr << " " << *onePtr <<endl;
//     cout << twoPtr << " " << *twoPtr <<endl;
// }