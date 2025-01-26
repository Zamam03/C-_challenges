#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {


    map<char, char> rotateRight = {
        {'N', 'E'},
        {'E', 'S'},
        {'S', 'W'},
        {'W', 'N'}
    };
    map<char, char> rotateLeft = {
        {'N', 'W'},
        {'E', 'N'},
        {'S', 'E'},
        {'W', 'S'}
    };


    int rows, cols, antRow, antCol, colour;
    char dir;

    cin >> rows >> cols >> antRow >> antCol >> dir;

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }
    colour = grid[antRow][antCol];
    grid[antRow][antCol] ^= 1; //flip bit
    if (colour == 0) {
        //white cell
        dir = rotateRight[dir];
    } else {
        dir = rotateLeft[dir];
    }
    switch (dir) {
        case 'N':
            --antRow;
            break;
        case 'S':
            ++antRow;
            break;
        case 'E':
            ++antCol;
            break;
        case 'W':
            --antCol;
            break;
    }
    cout << antRow << ' ' << antCol << ' ' << dir << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}

