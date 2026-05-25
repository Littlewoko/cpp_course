#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Test {
    virtual bool operator()(string &) = 0;
};

struct MatchTest: public Test {
    virtual bool operator()(string &t) {
        return t == "lion";
    }
};

void check(string t, Test &p) {
    cout << p(t) << endl;
}

int main() {
    MatchTest pred;

    string val = "lion";

    check(val, pred);

    return 0;
}



// class Animal {
//     public:
//     // = 0 means no implementation
//     // called a pure virtual function
//     // classes containing pure virtual funcs are abstract and cannot be instantiated
//     virtual void speak() = 0;
//     virtual void other() = 0;
// };

// class Dog: public Animal {
//     public:
//     virtual void speak() {
//         cout << "woof innit" <<endl;
//     }

//     // as dog does not implement all pure virtual of parent it is also abstract
// };

// you can create arrays of pointers to animals and use polymorphism on derived classes
// but cannot create a concrete array of animals as it will try to run the constructors




// class Parent {
// private:
//     int one;
// public:
//     Parent() : one {0} {}
//     // when using a child class as copy from we are "slicing" and losing data during the copy
//     // "two" is not copied
//     Parent(const Parent &other): one {0} {
//         cout << "copy parent" << endl;
//     }

//     // without virtual no lookup table is made and runtime will just call whatever the object type is
//     // with virtual the reference p calls the c print instead as the lookup table determines which to call
//     // important for proper polymorphism
//     virtual void print() {
//         cout << "parent" << endl;
//     }
// };

// class Child: public Parent {
// private:
//     int two;
// public:
//     Child(): two {1} {

//     }
//     void print() {
//         cout << "child" << endl;
//     }
// };

// int main() {

//     Child c;

//     Parent &p = c;
//     p.print();
//     c.print();

//     // copy initialisation
//     // copies the child into the parent
//     // doesn't assign a child object
//     Parent p2 = Child();
//     p2.print();

//     return 0;
// }










// bool match(string test) {
//     return test.size() == 3;
// }

// int m(vector<string>::iterator b, vector<string>::iterator e, bool (*p)(string)) {
//     int count = 0;
//     while (b != e) {
//         count += p(*b);
//         b++;
//     }

//     return count;
// }


// int main() {
//     vector<string> texts;
//     texts.push_back("one");
//     texts.push_back("two");
//     texts.push_back("three");
//     texts.push_back("two");
//     texts.push_back("four");
//     texts.push_back("two");
//     texts.push_back("three");

//     cout << count_if(texts.begin(), texts.end(), match) << endl;

//     cout << m(texts.begin(), texts.end(), match) << endl;

//     return 0;
// }



// void test() {
//     cout << "Hello" << endl;
// }

// void t2(int val) {
//     cout << val << endl;
// }

// int main() {
//     test();

//     // if you don't include the parentheses then the * binds to void, not pTest
//     void (*pTest)();

//     void (*pt2)(int) = t2;

//     // assign address of function to pTest
//     // pTest = &test;

//     // name of is pointer to function
//     pTest = test;

//     // again need parentheses to bind * as a dereference to pTest, not as the return type
//     // (*pTest)();
//     // doesn't need to be dereferenced as using () implied intention to call function
//     pTest();
//     t2(100);

//     return 0;
// }