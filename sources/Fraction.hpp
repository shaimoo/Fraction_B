#ifndef FRACTION
#define FRACTION
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace ariel
{

class Fraction{
private:
        int numerator;
        int denominator;
public:
    /// constructors
    Fraction();
    Fraction(int numerator , int denominator);
    Fraction(float num);

    ///help function
    Fraction reduce();
    bool checkoverflowplus(int num1 ,int num2);
    bool checkoverflowmul(int num1 ,int num2);
    int gcd(int number1, int number2);
    ///gets
    int getNumerator();
    int getDenominator();
    void setNumerator(int Numerator);
    void setDenominator(int Denominator);

    /// one operator
    Fraction operator+(float temp);
    Fraction operator-(float temp);
    Fraction operator*(float temp);
    Fraction operator/(float temp);
    Fraction operator+(const Fraction& temp) const;
    Fraction operator-(const Fraction& temp) const;
    Fraction operator/(const Fraction& temp) const;
    Fraction operator*(const Fraction& temp) const;


    /// add operator to object
    Fraction operator+=(const Fraction& temp);
    Fraction operator-=(const Fraction& temp);
    Fraction& operator++(); //prefix increment
    const Fraction operator++(int); //postfix increment
    Fraction& operator--(); //prefix increment
    const Fraction operator--(int); //postfix increment


    /// bool operators comper
     bool operator>(float temp);
     bool operator<(float temp);
    bool operator>=(float temp);
    bool operator<=(float temp);
    bool operator!=(float temp);
    bool operator==(float temp);
     bool operator>(const Fraction& temp1) const;
     bool operator<(const Fraction& temp1) const;
     bool operator>=(const Fraction& temp1) const;
     bool operator<=(const Fraction& temp1) const;
     bool operator==(const Fraction& temp1) const;
    bool operator!=(const Fraction& temp1) const;


    friend   Fraction operator+(float temp , const Fraction& temp1);
    friend   Fraction operator-(float temp , const Fraction& temp1);
    friend   Fraction operator*(float temp , const Fraction& temp1);
    friend   Fraction operator/(float temp , const Fraction& temp1);


    /// overload operator
    friend   bool operator>(float temp , const Fraction& temp1);
    friend   bool operator<(float temp , const Fraction& temp1);
    friend   bool operator>=(float temp , const Fraction& temp1);
    friend   bool operator<=(float temp , const Fraction& temp1);
    friend   bool operator==(float temp , const Fraction& temp1);
    friend   bool operator!=(float temp , const Fraction& temp1);
    friend ostream& operator<<(ostream& result, Fraction& temp);
    friend istream& operator>>(istream& result,Fraction& temp);
};



}
#endif