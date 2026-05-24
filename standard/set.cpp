#include <iostream>
#include <set>

using namespace std;

class Test {
    int id;
    string name;

    public:
    Test(int id, string name) : id {id}, name {name} {}

    void print() const {
        cout <<  id << ": " << name << endl;
    }

    bool operator <(const Test &other) const {
        return id < other.id;
    }
};

int main() {

    set<int> nums;

    nums.insert(10);
    nums.insert(10);
    nums.insert(20);
    nums.insert(5);

    for (auto num : nums) {
        cout << num << endl;
    }

    auto found = nums.find(10);

    if (found != nums.end()) {
        cout << "found: " << *found << endl;
    }

    set<Test> tests;

    tests.insert(Test(1, "Brad"));
    tests.insert(Test(1, "Brad"));
    tests.insert(Test(2, "Hello"));

    for (auto test : tests) {
        test.print();
    }

    return 0;
}