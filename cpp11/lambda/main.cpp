#include <iostream>
using namespace std;

void test(void (*func)()) {
    func();
}

void call(string name, void (*greet)(string)) {
    greet(name);
}

class T {
    private:
    int one = 1;
    int two = 2;
    public:
    void run() {
        int three = 3;
        int four = 4;

        // cannot capture on and two in capture list directly
        // we must capture this
        auto p = [this, three, four](){
            // this is captured by reference so values can be changed
            cout << one << two << three << four << endl;
        };
        p();
    }
};

int main() {
    T t;
    t.run();

    // lambda that takes no arguments and does nothing and gets called
    [](){}();

    auto func = [](){ cout << "Hello, world" << endl; };
    func();

    test(func);
    test([](){ cout << "Hello, world" << endl; });

    call("brad", [](string name){cout << "hello " << name << endl; });


    string a = "aye";
    string b = "ooo";

    // captures a and provides it to the scope of the lambda
    // passed by value
    [a](){cout << a << endl;}();

    // capture all local variables by value
    [=](){cout << a << endl;}();

    // capture b by reference and everything else by value
    // those captured by reference could be changed
    [=, &b](){cout << a << b << endl;}();

    // capture all local variables by reference
    [&](){a = "uh oh";}();
    cout << a << endl;

    // capture b by value and everything else by reference
    [&, b](){a = "yikes";}();
    cout << a << endl;

    return 0;
}