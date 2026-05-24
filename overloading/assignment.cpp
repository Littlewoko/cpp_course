#include <iostream>

using namespace std;

class Test {
    private:
    int id;
    string name;

    public:
    Test(): id {0}, name {""} {};
    Test(int id, string name): id {id}, name {name} {};
    Test(Test &other) {
        *this = other;
    }

    void print() const {
        cout << id << ": " << name << endl;
    }

    const Test &operator=(const Test &other) {

        id = other.id;
        name = other.name;

        return *this;
    }
};

int main() {

    Test t1(10, "brad");
    t1.print();

    Test t2(20, "alice");

    // assignment uses operator=
    t2 = t1;
    t2.print();

    // copy initialisation calls Test(Test &other)
    Test t3 = t1;
    t3.print();

    // rule of three
    // if you define copy constructor, operator =, or destructor
    // you should define the other two also

    return 0;
}