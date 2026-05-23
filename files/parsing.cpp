#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream infile;

    string fn = "stats.txt";

    infile.open(fn);
    if (infile.is_open()) {

        while (infile) {
            string line;

            getline(infile, line, ':');

            int population;
            infile >> population;

            // discard carriage return
            // infile.get();
            infile >> ws; // read all whitespace

            cout << "'" << line << "'" << " -- " << population << endl;
        }

        infile.close();
    } else {
        cout << "failed to open: " << fn << endl;
        return 1;
    }

    return 0;
}