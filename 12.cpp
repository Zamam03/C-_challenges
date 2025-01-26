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



    int colour, row, col;
    char dir;
    cin >> colour >> row >> col >> dir;
    if (colour == 0) {
       // white cell
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
    cout << (colour ^ 1) << endl; //flip bit
    cout << row << ' ' << col << ' ' << dir << endl;
    return 0;
}

