#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> nums(20);

    cout << "Size: " << nums.size() << endl;
    cout << "Capacity: " << nums.capacity() << endl;

    for (int i = 0; i < 10000; i++) {
        nums.push_back(i);
    }

    cout << "Size: " << nums.size() << endl;
    cout << "Capacity: " << nums.capacity() << endl;

    return 0;
}