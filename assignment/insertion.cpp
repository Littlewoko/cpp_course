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

    friend ostream &operator<<(ostream &out, const Test &to);
};

ostream &operator<<(ostream &out, const Test &to) {
    out << to.id << ": " << to.name;

    return out;
}

int main() {

    Test t1(10, "brad");

    t1.print();

    // left right associativity
    cout << t1 << endl;

    return 0;
}