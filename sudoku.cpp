#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sudoku {{5,3,0,   0,7,0,   0,0,0},
                            {6,0,0,   1,9,5,   0,0,0},
                            {0,9,8,   0,0,0,   0,6,0},

                            {8,0,0,   0,6,0,   0,0,3},
                            {4,0,0,   8,0,3,   0,0,1},
                            {7,0,0,   0,2,0,   0,0,6},

                            {0,6,0,   0,0,0,   2,8,0},
                            {0,0,0,   4,1,9,   0,0,5},
                            {0,0,0,   0,8,0,   0,7,9}};

bool inBox(int num, int row, int col) {
    for (int i = row - row % 3; i < row - row % 3 + 3; i++) {
        for (int j = col - col % 3; j < col - col % 3 + 3; j++) {
            if (num == sudoku[i][j])
                return true;
        }
    }
    return false;
}

bool inRow(int num, int row) {
    for (int i = 0; i < 9; i++) {
        if (num == sudoku[row][i])
            return true;
    }
    return false;
}

bool inCol(int num, int col) {
    for (int i = 0; i < 9; i++) {
        if (num == sudoku[i][col])
            return true;
    }
    return false;
}

bool isValid(int num, int row, int col) {
    if (inBox(num, row, col) || inRow(num, row) || inCol(num, col))
        return false;
    return true;
}

vector<int> findEmpty(vector<vector<int>> puzzle) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (!puzzle[row][col])
                return {row, col};
        }
    }
    return {};
}

void findValue(vector<vector<int>>& puzzle, int row, int col) {
    for (int val = 1; val < 10; val++) {
        if (isValid(val, row, col))
            puzzle[row][col] = val;
    }
}

vector<vector<int>> sudokuSolver(vector<vector<int>> puzzle) {
    while (!findEmpty(puzzle).empty()) {
        findValue(puzzle, findEmpty(puzzle)[0], findEmpty(puzzle)[1]);
    }
    return puzzle;
}

void printSudoku(vector<vector<int>> puzzle) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << sudokuSolver(sudoku)[row][col] << " ";
            if (!((col+1) % 3))
                cout << "  ";
        }
        cout << endl;
        if (!((row+1) % 3))
            cout << endl;
    }
}

int main() {
    printSudoku(sudoku);
    return 0;
}