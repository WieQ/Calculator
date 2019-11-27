#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),NW(new ButtonWidget),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    CM = new CalcMath;
    //Central Widget
    MW = new QWidget;
    setCentralWidget(MW);
    MWGL = new QGridLayout;
    MW->setLayout(MWGL);
    //end

    //NumberWidget
    NW = new ButtonWidget;
    NW->setFixedSize(this->width(),this->height()/2);

    for(int i = 0; i < NW->HMB;++i)
    connect(NW->GetMathButton(i),SIGNAL(clicked()),this,SLOT(NumberPressed()));

    connect(NW->GetSignButton("+"),SIGNAL(clicked()),this,SLOT(Add()));
    connect(NW->GetSignButton("-"),SIGNAL(clicked()),this,SLOT(Sub()));
    connect(NW->GetSignButton("*"),SIGNAL(clicked()),this,SLOT(Mul()));
    connect(NW->GetSignButton("/"),SIGNAL(clicked()),this,SLOT(Div()));
    connect(NW->GetSignButton("="),SIGNAL(clicked()),this,SLOT(Equ()));
    connect(NW->GetSignButton("+/-"),SIGNAL(clicked()),this,SLOT(CS()));
    connect(NW->GetSignButton("AC"),SIGNAL(clicked()),this,SLOT(Clear()));
    connect(NW->GetSignButton("M"),SIGNAL(clicked()),this,SLOT(Mem()));
    connect(NW->GetSignButton("M+"),SIGNAL(clicked()),this,SLOT(AddToMem()));
    connect(NW->GetSignButton("M-"),SIGNAL(clicked()),this,SLOT(SubFromMem()));


    //Display
    TB = new QLineEdit;
    TB->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    TB->setAlignment(Qt::AlignRight);
    QFont FA("Arial",18,false);
    FA.setBold(true);
    TB->setStyleSheet("QLineEdit{"
                      "background-color: gray;"
                      "border: 1px solid gray;"
                      "color: #ffffff;"
                      "}");
    TB->setFont(FA);
    TB->setReadOnly(true);

    MWGL->addWidget(TB);
    MWGL->addWidget(NW,1,0);
   }

MainWindow::~MainWindow()
{
    delete ui;
    delete CM;
    delete TB;
    delete MWGL;
    delete NW;
    delete MW;
}

void MainWindow::NumberPressed()
{
    MathButton *button = (MathButton *)sender();
    if(TB->text().toInt() == 0 || TB->text().toDouble() == 0.0)
        TB->setText(button->text());
    else
       TB->setText(QString::number((TB->text()+button->text()).toDouble(),'g',16));
}

void MainWindow::Add()
{
    CM->setFirstValue(TB->text().toDouble());
    TB->setText("+");
    CM->setSign('+');

}

void MainWindow::Sub()
{
    CM->setFirstValue(TB->text().toDouble());
    TB->setText("-");
    CM->setSign('-');
}

void MainWindow::Mul()
{
    CM->setFirstValue(TB->text().toDouble());
    TB->setText("*");
    CM->setSign('*');
}

void MainWindow::Div()
{
    CM->setFirstValue(TB->text().toDouble());
    TB->setText("/");
    CM->setSign('/');
}

void MainWindow::Equ()
{
    CM->setSecondValue(TB->text().toDouble());
    TB->setText(CM->result());
}

void MainWindow::CS()
{
    TB->setText(QString::number(TB->text().toDouble() * -1));
}

void MainWindow::Clear()
{
    CM->clear();
    TB->setText("0");
}

void MainWindow::Mem()
{
    if(CM->getMemoryValue() == 0.0)
        CM->setMemoryValue(TB->text().toDouble());
    else
        TB->setText(QString::number(CM->getMemoryValue()));
}

void MainWindow::AddToMem()
{
    CM->setMemoryValue(CM->getMemoryValue()+TB->text().toDouble());
}

void MainWindow::SubFromMem()
{
    CM->setMemoryValue(CM->getMemoryValue()- TB->text().toDouble());
}

