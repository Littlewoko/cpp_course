#include <iostream>
#include <map>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person() : name{""}, age{0} {}
    Person(string name, int age) : name{name}, age{age} {}

    // copy constructor
    Person(const Person &other) {
        cout << "copying" << endl;
        name = other.name;
        age = other.age;
    }

    // has to be const as anything called by first. must be const
    void print() const {
        cout << name << ": " << age << flush;
    }

    // reference for efficiency so we don't copy the original
    bool operator <(const Person &other) const {
        return age < other.age;
    }
};



int main() {

    map<Person, int> peeps;
    // this only works if the map is able to compare the Person objects for key sorting using < 
    peeps[Person("brad", 27)] = 0;
    // considers this a new key
    peeps[Person("brad", 20)] = 0;
    // does not consider this a new key as we only compare age in < (weird!)
    peeps[Person("abc", 20)] = 0;
    peeps[Person("alice", 26)] = 1;

    for (map<Person, int>::iterator i = peeps.begin(); i != peeps.end(); i++) {
        cout << i->second << ": " << flush;
        i->first.print();
        cout << endl;
    }


    return 0;
}