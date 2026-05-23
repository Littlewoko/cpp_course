#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string, int> ages;

    ages["mike"] = 40;
    ages["raj"] = 30;
    ages["brad"] = 27;

    pair<string, int> add("hello", 100);
    ages.insert(add);

    ages.insert(pair<string, int>("bing bong", 100));

    ages.insert(make_pair("bong bong", 100));

    cout << ages["brad"] << endl;

    // accessing element that is not in map adds it to map and initialises it to some default value (0 in this case)
    // cannot use access to look for presence
    cout << ages["john"] << endl;

    if (ages.find("tim") != ages.end()) {
        cout << "found tim" << endl;
    }

    for (map<string, int>::iterator i = ages.begin(); i != ages.end(); i++) {
        cout << i->first << ": " << i->second << endl;
    }

    for (map<string, int>::iterator i = ages.begin(); i != ages.end(); i++) {
        pair<string, int> age = *i; // value of iterator is a pair

        cout << age.first << ": " << age.second << endl;
    }

    return 0;
}