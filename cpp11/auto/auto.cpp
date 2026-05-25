#include <iostream>
#include <typeinfo>

using namespace std;

// template auto allows us to return template types
template<class T>
auto test(T val) -> decltype(val) {
    return val;
}

int main() {
    // infer type
    auto val = 7;

    cout << test("Hello, world") << endl;


    return 0;
}