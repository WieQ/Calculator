#ifndef CALCMATH_H
#define CALCMATH_H
#include <QString>

class CalcMath
{
public:
    CalcMath();
    void setFirstValue(double V1) {Value[0] = V1;}
    void setSecondValue(double V2) {Value[1] = V2;}
    void setSign(char s){sign = s;}
    void setMemoryValue(double VtoM) {MemValue = VtoM;}
    double getMemoryValue() const {return MemValue;}
    void clear(){Value[0] = Value[1] = MemValue = 0.0;}
    QString result();
private:
    double Value[2];
    double MemValue;
    char sign;
    QString res;
};

#endif // CALCMATH_H
