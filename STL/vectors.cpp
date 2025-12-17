#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1️⃣ Creating vectors
    vector<int> v1;                // empty vector
    vector<int> v2(5);             // size 5, default 0
    vector<int> v3(5, 10);         // size 5, all 10
    vector<int> v4 = {1, 2, 3, 4}; // initializer list

    // 2️⃣ Adding elements
    v1.push_back(5);
    v1.push_back(10);

    // 3️⃣ Accessing elements
    cout << v4[0] << " ";   // index operator
    cout << v4.at(2) << endl; // safer access

    // 4️⃣ Size & check empty
    cout << "Size: " << v1.size() << endl;
    cout << (v1.empty() ? "Empty" : "Not Empty") << endl;

    // 5️⃣ Iterating
    for (int a : v4) cout << a << " "; // range-based loop
    cout << endl;

    // 6️⃣ Removing elements
    v1.pop_back();  // remove last
    v1.clear();     // remove all

    // 7️⃣ Inserting elements
    v1.insert(v1.begin(), 100);  // insert at beginning

    // 8️⃣ Erase elements
    if (!v1.empty()) v1.erase(v1.begin()); // erase first element

    



    //Iterators and auto keyword

    

    vector<int>::iterator it;
    for(it = v1.begin(); it!= v1.end(); it++) {
        cout << *(it) << endl;
    }

    for(vector<int>::iterator it = v1.begin(); it!= v1.end(); it++) {
        cout << *(it) << endl;
    }

    for(auto it = v1.begin(); it!= v1.end(); it++) {
        cout << *(it) << endl;
    }

    //all three above are same
}

