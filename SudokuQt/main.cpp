#include "sudokugui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SudokuGUI w;
    w.show();
    return a.exec();
}
