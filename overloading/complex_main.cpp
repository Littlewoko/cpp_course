#include <iostream>
#include "complex.h"

using namespace std;
using namespace woko;

int main() {

    Complex c1(2,3);

    Complex c2 = c1;

    c1 = c2;

    cout << c1 << endl;

    Complex c3(10,10);
    c1 + c3;
    cout << c1 << endl;

    c1 = c1 + c3;
    cout << c1 << endl;

    return 0;
}