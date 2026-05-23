#include <iostream>
#include <vector>

using namespace std;

int main() {

    // initialise 4x3 grid (3 rows, 4 col)
    vector<vector<int>> grid(3, vector<int>(4, 0));

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << flush;
        }

        cout << endl;
    }

    cout << endl;

    // rows don't have to be same size, known as ragged array
    // rows are top down, so row 0 is the top of the grid
    grid[0].push_back(2);
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << flush;
        }

        cout << endl;
    }

    return 0;
}