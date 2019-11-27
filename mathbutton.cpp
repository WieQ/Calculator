#include "mathbutton.h"

MathButton::MathButton(QWidget *parent)
    :QPushButton (parent)
{

}

MathButton::~MathButton()
{

}

void MathButton::setAsNumberButton()
{
    setStyleSheet("QPushButton{background-color: #C0C0C0;"
                  "border:1px solid gray;"
                  "padding:5px;}"
                  "QPushButton:pressed{background-color: #A9A9A9;"
                  "border:1px solid gray;"
                  "padding:5px;}");
}

void MathButton::setAsModyfierButton()
{
    setStyleSheet("QPushButton{background-color: #FF8C00;"
                  "border:1px solid gray;"
                  "padding:5px;}"
                  "QPushButton:pressed{background-color: #FF4500;"
                  "border:1px solid gray;"
                  "padding:5px;}");
}
