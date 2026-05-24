#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Test {
    private:
    string name;
    public:
    Test(string name): name { name } {}
    ~Test() {
        // cout << "destroyed" << endl;
    }

    void print() {
        cout << name << endl;
    }
};

int main() {
    // LIFO
    stack<Test> st;

    st.push(Test("world"));
    st.push(Test("Hello"));

    // reference is more efficient as we avoid a copy operation, but can lead to issues
    Test &top = st.top(); 
    // as we're accessing a reference, popping and thus destroying the object leads to undefined behaviour
    // st.pop();
    top.print();

    top = st.top(); st.pop();
    top.print();

    return 0;
}