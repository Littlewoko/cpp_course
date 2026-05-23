#include <iostream>
#include <fstream>


using namespace std;

int main() {

    string fn = "test.txt";
    ifstream infile;

    infile.open(fn);
    if (infile.is_open()) {
        string line;
        // read word
        // infile >> line;

        // read line
        // getline(infile, line);
       

        // read all lines
        // boolean evaluation has been overloaded to this evaluates to while(!infile.eof())
        while (infile) {
            getline(infile, line);
            cout << line << endl;
        }

        infile.close();
    } else {
        cout << "failed to open file: " << fn << endl;
    }

    return 0;
}