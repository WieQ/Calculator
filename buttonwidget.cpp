#include "buttonwidget.h"

ButtonWidget::ButtonWidget(QWidget *parent)
    :QWidget(parent)
{
    NBWL = new QGridLayout;
    setLayout(NBWL);
    NB[0] = new MathButton;
    NB[0]->setText(QString::number(0));
    NB[0]->setAsNumberButton();
    NBWL->addWidget(NB[0],3,1);
    int J = 2;
    for(int i = 1 ;i<HMB;++i)
    {
        NB[i] = new MathButton;
        NB[i]->setText(QString::number(i));
        NB[i]->setAsNumberButton();
        switch(i%3)
        {
        case 1:
            NBWL->addWidget(NB[i],J,0);
            break;
        case 2:
            NBWL->addWidget(NB[i],J,1);
            break;
        case 0:
            NBWL->addWidget(NB[i],J--,2);
        };
    }
    for(int i = 0; i < HMB;++i){
        SB[i] = new MathButton;
        SB[i]->setAsModyfierButton();
    }
    SB[0]->setText("/");
    NBWL->addWidget(SB[0],0,3);
    SB[1]->setText("*");
    NBWL->addWidget(SB[1],1,3);
    SB[2]->setText("+");
    NBWL->addWidget(SB[2],2,3);
    SB[3]->setText("-");
    NBWL->addWidget(SB[3],3,3);
    SB[4]->setText("=");
    NBWL->addWidget(SB[4],3,4);
    SB[5]->setText("M+");
    NBWL->addWidget(SB[5],0,4);
    SB[6]->setText("M-");
    NBWL->addWidget(SB[6],1,4);
    SB[7]->setText("M");
    NBWL->addWidget(SB[7],2,4);
    SB[8]->setText("AC");
    NBWL->addWidget(SB[8],3,0);
    SB[9]->setText("+/-");
    NBWL->addWidget(SB[9],3,2);
}

ButtonWidget::~ButtonWidget()
{

    for(int i = 0;i<HMB;++i)
    {
        delete NB[i];
        delete SB[i];
    }
    delete NBWL;

}
MathButton * ButtonWidget::GetMathButton(int i) const
{
    if(i > HMB)
        return nullptr;
    else
        return NB[i];
}

MathButton *ButtonWidget::GetSignButton(QString S) const
{
    for(int i = 0; i<HMB;++i)
        if(SB[i]->text() == S)
            return SB[i];
    return nullptr;
}

