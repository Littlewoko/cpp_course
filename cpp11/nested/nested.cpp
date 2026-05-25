#include <iostream>
#include "ring.h"
using namespace std;


int main() {
    ring<string> textring(3);
    textring.add("1");
    textring.add("2");
    textring.add("3");
    textring.add("4");
    textring.add("5");

    for (int i = 0; i < textring.size(); i++) {
        cout << textring.get(i) << endl;
    }

    cout << endl;

    for (ring<string>::iterator it = textring.begin(); it != textring.end(); ++it) {
        cout << *it << endl;
    }

    cout << endl;
    
    for (string val : textring) {
        cout << val << endl;
    }

}