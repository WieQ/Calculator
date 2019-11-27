#include "calcmath.h"

CalcMath::CalcMath()
{
MemValue = Value[0] = Value[1] = 0.0;
}

QString CalcMath::result()
{
    switch(sign)
    {
    case '+':
        return QString::number(Value[0]+Value[1]);
    case '-':
        return QString::number(Value[0]-Value[1]);
    case '*':
        return QString::number(Value[0]*Value[1]);
    case '/':
        if(Value[1] == 0.0)
            return "Błąd Dzielenie przez Zero";
        else
            return QString::number((Value[0]/Value[1]));
    }
    return "0";
}
