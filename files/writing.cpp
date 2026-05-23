#include <iostream>
#include <fstream>


using namespace std;

int main() {
    ofstream outf;
    // can also use fstream

    string fn = "text.txt";
    outf.open(fn);
    // and fstream.open(fn, ios::out)
    // have to tell the fstream that it's an output file

    if (outf.is_open()) {
        outf << "Hello, world" << endl;
        outf << "Nice to see you..." << endl;
        outf << 123 << endl;
        outf.close();
    } else {
        cout << "could not open file: " << fn << endl;
    }

    return 0;
}