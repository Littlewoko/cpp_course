#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> ss;


    ss.push_back("one");
    ss.push_back("two");
    ss.push_back("three");

    vector<string>::iterator it;
    it = ss.begin();

    cout << *it << endl;

    for (auto itx = ss.begin(); itx != ss.end(); itx++) {
        cout << *itx << endl;
    }

    return 0;
}