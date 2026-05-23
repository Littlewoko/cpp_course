#include <iostream>
#include <map>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string name, int age) : name{name}, age{age} {}

    // copy constructor
    Person(const Person &other) {
        cout << "copying" << endl;
        name = other.name;
        age = other.age;
    }

    void print() const {
        cout << name << ": " << age << endl;
    }
};



int main() {

    map<int, Person> peeps;

    // [] operator actually tries to create default constructoed person and then overwrite it which fails
    // need to use insert
    // peeps[0] = Person("Brad", 27);
    // peeps[1] = Person("Alice", 26);
    // peeps[2] = Person("Xander", 14);

    peeps.insert({0, Person("brad", 27)});
    peeps.insert({1, Person("alice", 26)});
    peeps.insert({2, Person("xander", 14)});


    // keys are sorted
    for (map<int, Person>::iterator i = peeps.begin(); i != peeps.end(); i++) {
        i->second.print();
    }

    return 0;
}