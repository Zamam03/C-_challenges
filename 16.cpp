#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Ant {
public:

    Ant(int row, int col) : mRow(row), mCol(col), mDir('N') {
    }

    pair<int, int> getPosition() const {
        return make_pair(mRow, mCol);
    }

    void update(int colour, int maxRows, int maxCols) {
        if (colour == 0) {
            mDir = rotateRight[mDir];
        } else {
            mDir = rotateLeft[mDir];
        }
        switch (mDir) {
            case 'N':
                mRow = (mRow - 1 + maxRows) % maxRows;
                break;
            case 'S':
                mRow = (mRow + 1) % maxRows;
                break;
            case 'E':
                mCol = (mCol + 1) % maxCols;
                break;
            case 'W':
                mCol = (mCol - 1 + maxCols) % maxCols;
                break;
        }
    }

private:

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

    int mRow, mCol;
    char mDir;  //N, S, E, W
};

class Grid {
public:

    Grid(int rows, int cols) : mRows(rows), mCols(cols), mGrid(rows, vector<int>(cols)) {
    }

    void addAnt(int row, int col) {
        Ant ant(row, col);
        mAnts.push_back(ant);
    }

    void step() {
        set<pair<int, int>> cells;
        for (Ant &ant : mAnts) {
            pair<int, int> pos = ant.getPosition();
            cells.insert(pos);
            ant.update(mGrid[pos.first][pos.second], mRows, mCols);
        }
        for (auto cell : cells) {
            mGrid[cell.first][cell.second] ^= 1; //flip the bit
        }
    }

    friend ostream& operator<<(ostream& os, const Grid& grid) {
        for (int row = 0; row < grid.mRows; ++row) {
            for (int col = 0; col < grid.mCols; ++col) {
                os << grid.mGrid[row][col];
            }
            os << endl;
        }
        return os;
    }

private:
    const int mRows;
    const int mCols;
    vector<Ant> mAnts;
    vector<vector<int>> mGrid;

};

int main() {
    int T;
    cin >> T;
    int A;
    cin >> A;
    int rows, cols;
    cin >> rows >> cols;
    Grid grid(rows, cols);
    for (int a = 0; a < A; ++a) {
        int antRow, antCol;
        cin >> antRow >> antCol;
        grid.addAnt(antRow, antCol);
    }
    cout << grid;
    for (int t = 0; t < T; ++t) {
        grid.step();
        cout << endl << grid;
    }
    return 0;
}

