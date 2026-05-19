#include <iostream>

using namespace std;

class CanGoWrong {
    public:
    CanGoWrong() {
        // will throw for bad alloc
        char *pMem = new char[999999999999999];
        delete [] pMem;
    }
};

int main() {
    try {
        CanGoWrong wrong;
    } catch (bad_alloc &e) {
        cout << e.what() << endl;
    }

    return 0;
}