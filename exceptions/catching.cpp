#include <iostream>
#include <exception>

using namespace std;

void goesWrong() {
    bool err = true;
    bool err2 = false;

    if (err) {
        throw bad_alloc();
    }

    if (err2) {
        throw exception();
    }
}


int main() {

    try {
        goesWrong();
    } catch (exception &e) {
        cout << e.what() << endl;
    } catch (bad_alloc &e) { // never enters
        cout << e.what() << endl;
    }

    return 0;
}