#include <iostream>
#include <fstream>

using namespace std;

// struct is padded to make it more efficient
// need to turn off padding for reading and writing of bin data for struct
// push directive 1 which is to align following data on single byte boundaries (no padding)
#pragma pack(push, 1)
struct Person {
    char name[50];
    int age;
    double weight;
};

// remove directive 1 from the pragma pack to enable padding
#pragma pack(pop)

int main() {

    string fn = "test.bin";

    // write step //
    ofstream out;
    out.open(fn, ios::binary);

    if (!out.is_open()) {
        cout << "could not open: " << fn << endl;
    }

    Person someone = {"Bradley", 27, 81.3};
    // turn the pointer to struct into string (old world)
    // out.write((char *) &someone, sizeof(Person));

    // new world
    out.write(reinterpret_cast<char *>(&someone), sizeof(Person));

    out.close();

    // read step //
    Person readp = {};

    ifstream in;
    in.open(fn, ios::binary);

    if (!in.is_open()) {
        cout << "could not open: " << fn << endl;
    }

    in.read(reinterpret_cast<char *>(&readp), sizeof(Person));

    cout << readp.name << ", " << readp.age << ", " << readp.weight << endl;

    in.close();
    return 0;
}