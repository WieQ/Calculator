#ifndef NUMBERBUTTON_H
#define NUMBERBUTTON_H
#include <QPushButton>

class MathButton: public QPushButton
{
    Q_OBJECT
public:
    MathButton(QWidget *parent = nullptr);
    virtual ~MathButton ();
    void setAsNumberButton();
    void setAsModyfierButton();


};

#endif // NUMBERBUTTON_H
