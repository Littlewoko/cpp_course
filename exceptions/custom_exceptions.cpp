#include <iostream>
#include <exception>

using namespace std;

class my_exception: public exception {
    public:
    virtual const char* what() const throw() {
        return "my_exception";
    }
};

class test {
    public:
    void goesWrong() {
        throw my_exception();
    }
};

int main() {

    test _test;
    try {
        _test.goesWrong();
    } catch (my_exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}