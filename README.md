# Sudoku Solver

## Introduction

"Sudoku Solver" is a standard 9x9 sudoku solver GUI designed with Qt-based C++. The GUI is designed for Windows computers, but the outline code for the back-tracking algorithm is also provided. "Sudoku Solver" allows the user to enter any valid sudoku into the displayed grid where it is then able to be solved. (Note: A sudoku is only guaranteed to be unique if there are at least 17 given digits, otherwise the solver only offers one of the possible solutions.) Visit [Projects](http://iangsohan.com/projects.html) to see a visual.

## Code Samples

Solves Sudoku:
```
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
```
<br />

Determines Valid Value:
```
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
```
<br />

Determines Solveable Sudoku:
```
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
```

## Installation

Windows Executable:
1. Download [SudokuSolver.exe](https://github.com/iangsohan/Sudoku/blob/master/SudokuSolver.exe?raw=true)
2. Enter Sudoku Values.
3. Press ``Enter`` to Solve.

Ubuntu Linux:
1. Download [sudoku.cpp](https://github.com/iangsohan/Sudoku/blob/master/sudoku.cpp).
2. Change Given Sudoku (``0`` for Empty)
```
vector<vector<int>> sudoku {{0, 0, 5,   3, 0, 0,   0, 0, 0},
                            {8, 0, 0,   0, 0, 0,   0, 2, 0},
                            {0, 7, 0,   0, 1, 0,   5, 0, 0},

                            {4, 0, 0,   0, 0, 5,   3, 0, 0},
                            {0, 1, 0,   0, 7, 0,   0, 0, 6},
                            {0, 0, 3,   2, 0, 0,   0, 8, 0},

                            {0, 6, 0,   5, 0, 0,   0, 0, 9},
                            {0, 0, 4,   0, 0, 0,   0, 3, 0},
                            {0, 0, 0,   0, 0, 9,   7, 0, 0}};
```
3. Open Ubuntu Linux terminal.
4. ``clang++ sudoku.cpp``
5. Solved Sudoku is Printed
```
1 4 5   3 2 7   6 9 8 
8 3 9   6 5 4   1 2 7 
6 7 2   9 1 8   5 4 3 

4 9 6   1 8 5   3 7 2 
2 1 8   4 7 3   9 5 6 
7 5 3   2 9 6   4 8 1 

3 6 7   5 4 2   8 1 9 
9 8 4   7 6 1   2 3 5 
5 2 1   8 3 9   7 6 4 
```

Qt Open Source:
1. Download [Qt Open Source Installer](https://www.qt.io/download-thank-you?hsLang=en) Installer
2. Select Most Recent Version to Download
3. Download [SudokuQt](https://github.com/iangsohan/Sudoku/tree/master/SudokuQt) Folder
4. Open "SudokuGUI" Project
5. Select "Release" and "Build"

## License

[MIT](https://choosealicense.com/licenses/mit/)
