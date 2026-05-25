#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class T {
    public:
    T(initializer_list<string> ts) {
        for (auto t: ts) {
            cout << t << endl;
        }
    }
};

int main() {
    vector<int> nums {1, 2, 3};
    cout << nums[1] <<endl;

    T t{"a", "b", "c"};


    return 0;
}