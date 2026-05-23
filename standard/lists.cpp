#include <iostream>
// linked list (double ended)
#include <list>

using namespace std;

int main() {

    list<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    nums.push_front(0);

    for (list<int>::iterator i = nums.begin(); i != nums.end(); i++) {
        cout << *i << endl;
    }

    cout << endl;

    list<int>::iterator i = nums.begin();
    i++;
    // insert into second position
    // pushes passed iterator back and places num there
    nums.insert(i, 100);
    // removes item pointed to by iterator i from list
    // returns iterator to element that will take it's place
    i = nums.erase(i);

    // you can modify as you iterate
    for (list<int>::iterator i = nums.begin(); i != nums.end(); i++) {
        if (*i == 2) {
            nums.insert(i, 5);
        }

        if (*i == 1) {
            i = nums.erase(i);
            i--;
        }
    }

    for (list<int>::iterator i = nums.begin(); i != nums.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}