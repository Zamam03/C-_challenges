#include <iostream>
#include <vector>
#include <map>

using namespace std;

static map<char, char> rotateRight = {
    {'N', 'E'},
    {'E', 'S'},
    {'S', 'W'},
    {'W', 'N'}
};
static map<char, char> rotateLeft = {
    {'N', 'W'},
    {'E', 'N'},
    {'S', 'E'},
    {'W', 'S'}
};

void print(vector<vector<int>> grid) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void updateAnt(int colour, int &row, int &col, char &dir) {
    if (colour == 0) {
        dir = rotateRight[dir];
    } else {
        dir = rotateLeft[dir];
    }
    switch (dir) {
        case 'N':
            --row;
            break;
        case 'S':
            ++row;
            break;
        case 'E':
            ++col;
            break;
        case 'W':
            --col;
            break;
    }
}

int main() {

    int T;
    cin >> T;
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));

    int antRow, antCol;
    cin >> antRow >> antCol;
    char dir = 'N';
    print(grid);
    for (int t = 0; t < T; ++t) {
        int colour = grid[antRow][antCol];
        grid[antRow][antCol] ^= 1; //flip bit
        updateAnt(colour, antRow, antCol, dir);
        cout << endl;
        print(grid);
    }
    return 0;
}

