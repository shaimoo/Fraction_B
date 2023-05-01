#include "Fraction.hpp"
#include <math.h>
using namespace std;
namespace ariel{


    Fraction::Fraction():numerator(0),denominator(1){}
    Fraction::Fraction(float num)
    {

    *this = Fraction(round(num*=1000),1000);
    *this = this->reduce();
    }
    Fraction::Fraction(int numerator, int denominator):numerator(numerator),denominator(denominator) {
        if (denominator == 0 ){
            throw invalid_argument("");
        }
     }

    ostream& operator<<(ostream& result, Fraction &temp) {
        temp.reduce();
        if(temp.getDenominator()<0){
            temp.denominator *= -1;
            temp.numerator *= -1;
        }
        result <<   temp.numerator << "/" << temp.denominator ;
    return result;
}

Fraction Fraction::operator+(float temp){
    Fraction result(temp);
    return (*this) + result;
}

Fraction Fraction::operator+(const Fraction &temp) const {
    int mone = numerator * temp.denominator  + denominator * temp.numerator;
    int mehane = denominator * temp.denominator;
    Fraction result(mone,mehane);
    result.checkoverflowplus(numerator * temp.denominator, denominator * temp.numerator);

    if (mone == mehane){
        return Fraction(1,1);
    }
    result.checkoverflowmul(numerator,temp.denominator);
    result.checkoverflowmul(denominator, temp.numerator);


    if(result.getDenominator()<0){
        result.denominator *= -1;
        result.numerator *= -1;
    }
    result.reduce();
    return result;
}


    Fraction Fraction::operator-(const Fraction &temp) const {
        int mone = numerator * temp.denominator  - denominator * temp.numerator;
        int mehane = denominator * temp.denominator;
        if (mone == mehane){
            return Fraction(1,1);
        }
        Fraction result(mone,mehane);
        if(result.getDenominator()<0){
            result.denominator *= -1;
            result.numerator *= -1;
        }
        if(temp == 1){
            return Fraction(numerator-denominator,denominator);
        }
        if (!result.checkoverflowplus(temp.numerator, -numerator) ||
            !result.checkoverflowplus(temp.denominator, -denominator)) {
            throw std::overflow_error("Overflow detected!");
        }
        result.reduce();
        return result;
    }



Fraction Fraction::operator+=(const Fraction &temp)  {
    *this = *this+temp;
    return *this;
}

Fraction Fraction::operator-=(const Fraction &temp)  {
    *this = *this-temp;
    return *this;
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

const Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    numerator += denominator;
    return temp;
}

Fraction &Fraction::operator--() {
    numerator-= denominator;
    return *this;
}

const Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    numerator-= denominator;
    return temp;
}

Fraction Fraction::operator/(const Fraction &temp) const {
    if (temp.numerator == 0 ){
        throw std::runtime_error("cant divide by zero");
    }
    if(temp.denominator== temp.numerator){
        return *this;
    }
    Fraction result(numerator*temp.denominator,denominator*temp.numerator);
    result.reduce();
    result.checkoverflowmul(temp.numerator,numerator);
    result.checkoverflowmul(temp.denominator,denominator);
    return result;
}

Fraction Fraction::operator*(const Fraction &temp)  const {
        if(temp.denominator== temp.numerator){
            return *this;
        }
        if(*this==1){
            return Fraction(temp);
        }
    Fraction result(numerator*temp.numerator,denominator*temp.denominator);
    result.reduce();
    result.checkoverflowmul(temp.numerator,numerator);
    result.checkoverflowmul(temp.denominator,denominator);
    return result;
}

Fraction Fraction::operator-(float temp){
    return (*this)-Fraction(temp);
}


    Fraction Fraction::operator*(float temp){
        return Fraction(temp)* *this;
    }


    bool Fraction::operator>=(const Fraction &temp1) const {
        float x = float(temp1.numerator) / float(temp1.denominator);
        float y = float(numerator)/float (denominator);
    return y>=x;
}

    bool Fraction::operator<=(const Fraction &temp1) const {
        float x = float(temp1.numerator) / float(temp1.denominator);
        float y = float(numerator)/float (denominator);
        return y<=x;
    }
    bool Fraction::operator<(float temp){
        return *this<Fraction(temp);
    }
bool Fraction::operator>(float temp){
    return *this>Fraction(temp);
}


bool Fraction::operator>(const Fraction &temp) const {
    float result = float(temp.numerator)/float(temp.denominator);
    float result2 = float(numerator)/float(denominator);
    return result2>result;
}

    Fraction operator*(float temp, const Fraction &frank) {
        return frank*temp;
    }

    bool Fraction::operator<(const Fraction &temp) const {
        float result = float(temp.numerator)/float(temp.denominator);
        float result2 = float(numerator)/float(denominator);
        return result2<result;
    }

    bool Fraction::operator>=(float temp){
        return *this>=Fraction(temp);
    }

    bool Fraction::operator==(const Fraction &temp1) const {
        Fraction result = temp1;
        result.reduce();
        float ans = float(result.getNumerator())/float(result.getDenominator());
        float finish = float(numerator)/float(denominator);
        /// make round of the numbers 3 digits.
        Fraction a (ans);
        Fraction b (finish);
        float ans1 = float(a.getNumerator())/float(a.getDenominator());
        float ans2 = float(b.getNumerator())/float(b.getDenominator());
        return ans1 == ans2;
    }

    bool Fraction::operator==(float temp) {
        return *this==Fraction(temp);
    }
    Fraction Fraction::operator/(float temp) {
        if (temp == 0){
            throw runtime_error("cant divided by 0");
        }
        Fraction temp2(temp);
        Fraction result(temp2.denominator,temp2.numerator);
        return *this*(result);
    }

    bool Fraction::operator<=(float temp) {
        return *this<=Fraction(temp);
    }

    bool Fraction::operator!=(float temp) {
        return *this!=Fraction(temp);
    }

    Fraction operator+(float temp, const Fraction &temp1) {
        return Fraction(temp)+temp1;
    }

    Fraction operator-(float temp, const Fraction &temp1) {
        return Fraction(temp)-temp1;
    }

    Fraction operator/(float temp, const Fraction &temp1) {
        return Fraction(temp)/temp1;
    }

    bool operator>(float temp, const Fraction &temp1) {
        return Fraction(temp)>temp1;
    }

    bool operator<(float temp, const Fraction &temp1) {
        return Fraction(temp)<temp1;
    }

    bool operator>=(float temp, const Fraction &temp1) {
        return Fraction(temp)>=temp1;
    }

    bool operator<=(float temp, const Fraction &temp1) {
        return Fraction(temp)<=temp1;
    }

    bool operator==(float temp, const Fraction &temp1) {
        return Fraction(temp)==temp1;
    }

    bool operator!=(float temp, const Fraction &temp1) {
        return Fraction(temp)!=temp1;
    }

    bool Fraction::operator!=(const Fraction &temp1) const {
        return !(*this==temp1);
    }

    istream &operator>>(istream &result, Fraction &temp) {
        int mone , mehane;

        if(result.peek() == EOF){
            throw std::runtime_error("error not full number");
        }
        result >> mone;
        if(result.peek() == '.'){
            throw std::runtime_error("error");
        }
        if(result.peek() == EOF){
            throw std::runtime_error("error not full number");
        }
        result >> mehane;
        if (mehane == 0){
            throw std::runtime_error("error can divide by zero");
        }
        temp = Fraction(mone, mehane);
        return result;
    }

    Fraction Fraction::reduce(){
        int gcdVal = gcd(numerator, denominator); // Use different variable name
        numerator /= gcdVal;
        denominator /= gcdVal;
        return Fraction(numerator,denominator);
    }

    int Fraction::gcd(int number1, int number2) {
        if (number2 == 0) {
            return number1;
        }
        return gcd(number2, number1 % number2);
    }


    int Fraction::getNumerator() {
        return numerator;
    }

    int Fraction::getDenominator()  {
        return denominator;
    }


    bool Fraction::checkoverflowplus(int num1, int num2) {
        if (num1>0 && num2>0 && (num1 + num2)<0) {
            throw std::overflow_error("");
        }
        if (num1<0 && num2<0 && (num1 + num2)>0) {
            throw std::overflow_error("");
        }
        return true;
    }



    bool Fraction::checkoverflowmul(int num1, int num2) {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if (num1 * num2 >= max_int || num1 * num2 <= min_int ){
            throw overflow_error("");
        }
        if ((num1 == max_int && num2 >= 1 )|| ( num2 == max_int && num1>=1 )){
            throw overflow_error("");
        }
        if ((num1 == min_int && num2 <= 0 )|| ( num2 == min_int && num1<=0 )){
            throw overflow_error("");
        }

        return true;

    }

    void Fraction::setNumerator(int Numerator) {
    this->numerator = Numerator;
    }

    void Fraction::setDenominator(int Denominator) {
        this->denominator = Denominator;
    }
}
