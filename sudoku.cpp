#include <iostream>
#include <vector>
using namespace std;

// Valid Value
bool valid(vector<vector<int>> sudoku, int val, int row, int col) {
    for (int i = row - row % 3; i < row - row % 3 + 3; i++)
        for (int j = col - col % 3; j < col - col % 3 + 3; j++)
            if (val == sudoku[i][j])
                return false;
    for (int i = 0; i < 9; i++)
        if (val == sudoku[row][i] || val == sudoku[i][col])
            return false;
    return true;
}

bool solvable(vector<vector<int>> sudoku) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (sudoku[row][col] != 0) {
                int val = sudoku[row][col];
                sudoku[row][col] = 0;
                if (!valid(sudoku, val, row, col))
                    return false;
            }
        }
    }
    return true;
}

// Empty Sudoku Slots
bool available(vector<vector<int>> sudoku, int& row, int& col) {
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (!sudoku[row][col])
                return true;
    return false;
}

// Standard Backtracking Algorithm
bool solver(vector<vector<int>>& sudoku) {
    int row, col;
    if (!solvable(sudoku))
        return false;
    if (!available(sudoku, row, col))
        return true;
    for (int val = 1; val <= 9; val++) {
        if (valid(sudoku, val, row, col)) {
            sudoku[row][col] = val;
            if (solver(sudoku))
                return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}

// Prints Sudoku
void print(vector<vector<int>> sudoku) {
    solver(sudoku);
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << sudoku[row][col] << " ";
            if (!((col+1) % 3) && col != 8)
                cout << "  ";
        }
        cout << endl;
        if (!((row+1) % 3) && row != 8)
            cout << endl;
    }
}

int main() {
    vector<vector<int>> sudoku {{0, 0, 5,   3, 0, 0,   0, 0, 0},
                                {8, 0, 0,   0, 0, 0,   0, 2, 0},
                                {0, 7, 0,   0, 1, 0,   5, 0, 0},

                                {4, 0, 0,   0, 0, 5,   3, 0, 0},
                                {0, 1, 0,   0, 7, 0,   0, 0, 6},
                                {0, 0, 3,   2, 0, 0,   0, 8, 0},

                                {0, 6, 0,   5, 0, 0,   0, 0, 9},
                                {0, 0, 4,   0, 0, 0,   0, 3, 0},
                                {0, 0, 0,   0, 0, 9,   7, 0, 0}};
    print(sudoku);
    return 0;
}