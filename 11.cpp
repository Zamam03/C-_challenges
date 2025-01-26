#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}

