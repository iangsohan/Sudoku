#include "sudokugui.h"
#include "ui_sudokugui.h"
#include <vector>
#include <iostream>
#include <QKeyEvent>
using namespace std;

SudokuGUI::SudokuGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SudokuGUI)
{
    ui->setupUi(this);

    connect(SudokuGUI::findChild<QPushButton *>("SolveButton"), SIGNAL(released()), this, SLOT(SolveButton()));
    connect(SudokuGUI::findChild<QPushButton *>("ClearButton"), SIGNAL(released()), this, SLOT(ClearButton()));
}

SudokuGUI::~SudokuGUI() {
    delete ui;
}

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

// Valid Sudoku
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

// Solves Sudoku
void SudokuGUI::SolveButton() {
    vector<vector<int>> sudoku {};
    for (int row = 1; row < 10; row++) {
        sudoku.push_back({});
        for (int col = 1; col < 10; col++) {
            QString lineName = "LineEdit" + QString::number(row) + QString::number(col);
            QString text = SudokuGUI::findChild<QLineEdit *>(lineName)->displayText();
            if (text != " ")
                sudoku.back().push_back(text.toInt());
            else
                sudoku.back().push_back(0);
        }
    }
    if (solvable(sudoku))
        solver(sudoku);
    for (int row = 1; row < 10; row++) {
        for (int col = 1; col < 10; col++) {
            QString lineName = "LineEdit" + QString::number(row) + QString::number(col);
            QString text = SudokuGUI::findChild<QLineEdit *>(lineName)->displayText();
            QLineEdit* lineEdit = SudokuGUI::findChild<QLineEdit *>(lineName);
            lineEdit->setReadOnly(true);
            if (text == " ") {
                lineEdit->setStyleSheet(lineEdit->styleSheet() + "QLineEdit { color: green; font-weight: normal }");
                lineEdit->setText(QString::number(sudoku[row-1][col-1]));
            }
        }
    }
}

// Clears Sudoku
void SudokuGUI::ClearButton() {
    for (int row = 1; row < 10; row++) {
        for (int col = 1; col < 10; col++) {
            QString lineName = "LineEdit" + QString::number(row) + QString::number(col);
            QLineEdit* lineEdit = SudokuGUI::findChild<QLineEdit *>(lineName);
            lineEdit->setStyleSheet(lineEdit->styleSheet() + "QLineEdit { color: black; font-weight: bold; }");
            lineEdit->setText("");
            lineEdit->setReadOnly(false);
        }
    }
}
