#include <iostream>

void mightGoWrong() {

    bool err = true;

    if(err) {
        throw 8;
    }
}

int main() {
    mightGoWrong();

    return 0;
}