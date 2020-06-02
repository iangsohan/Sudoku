#ifndef SUDOKUGUI_H
#define SUDOKUGUI_H

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class SudokuGUI; }
QT_END_NAMESPACE

class SudokuGUI : public QMainWindow
{
    Q_OBJECT

public:
    SudokuGUI(QWidget *parent = nullptr);
    ~SudokuGUI();

private:
    Ui::SudokuGUI *ui;

private slots:
    void SolveButton();
    void ClearButton();
};
#endif // SUDOKUGUI_H
