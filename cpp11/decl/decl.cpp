#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    int val;

    // prints i for integer
    // d for integer
    cout << typeid(val).name() << endl;

    string s;

    // prints nonsense
    // name handling adds chars to name to help type handling
    // typeid name on objs causes mangling
    cout << typeid(s).name() << endl;

    // declare type and copy type from other
    decltype(s) name = "bob";

    cout << typeid(name).name() << endl;
    cout << name << endl;

    return 0;
}