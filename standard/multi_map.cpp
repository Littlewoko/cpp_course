#include <iostream>
#include <map>

using namespace std;

int main() {
    multimap<int, string> lookup;

    lookup.insert({30, "Brad"});
    lookup.insert({10, "Alice"});
    // duplicate keys are stored, not replaced
    lookup.insert({30, "Xander"});
    lookup.insert({20, "Thom"});
    lookup.insert({40, "Some name"});

    for (multimap<int, string>::iterator i = lookup.begin(); i != lookup.end(); i++) {
        cout << i->first << ": " << i->second << endl;
    }

    // finds iterator of first matching element and then continue
    for (multimap<int, string>::iterator i = lookup.find(30); i != lookup.end(); i++) {
        cout << i->first << ": " << i->second << endl;
    }

    cout << endl;

    // can just use auto
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

// first is start of range, second is just past end of range
    for (multimap<int, string>::iterator i = its.first; i != its.second; i++) {
        cout << i->first << ": " << i->second << endl;
    }

    return 0;
}