#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H
#include "mathbutton.h"
#include <QGridLayout>

class ButtonWidget:public QWidget
{
    Q_OBJECT
public:
    ButtonWidget(QWidget *parent = nullptr);
    virtual ~ButtonWidget()    ;
    static const int HMB = 10;
private:
    MathButton *NB[HMB];
    MathButton *SB[HMB];
    QGridLayout *NBWL;
    QString NP;
public:
    QString GetNumberPressed() const {return NP;}
    MathButton * GetMathButton(int i) const;
    MathButton * GetSignButton(QString S) const;

};

#endif // BUTTONWIDGET_H
