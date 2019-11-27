#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "buttonwidget.h"
#include "calcmath.h"
#include <QLineEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QWidget *MW;
    ButtonWidget *NW;
    QLineEdit *TB;
    CalcMath *CM;
    QGridLayout *MWGL;
    Ui::MainWindow *ui;
private slots:
    void NumberPressed();
    void Add();
    void Sub();
    void Mul();
    void Div();
    void Equ();
    void CS();
    void Clear();
    void Mem();
    void AddToMem();
    void SubFromMem();

};

#endif // MAINWINDOW_H
