#include <iostream>

using namespace std;

void mightGoWrong() {

    bool err = true;

    if(err) {
        throw 8;
    }
}

int main() {
    try {
        mightGoWrong();

    } catch (int e) {
        cout << "Error code " << e << endl;
    }

    return 0;
}