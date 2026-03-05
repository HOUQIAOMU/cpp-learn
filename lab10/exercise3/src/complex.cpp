#include <iostream>
#include "lab10/exercise3/include/complex.hpp"

// 1. overload operator<<, which is friend function
 std::ostream & operator<<(std::ostream & os, const Complex & complex)
 {
    if(complex.imag >= 0)
    {
        std::string str = std::to_string(complex.real)+"+"+std::to_string(complex.imag)+"i";
        os<<str;
        return os;
    }
    else
    {
        std::string str = std::to_string(complex.real)+std::to_string(complex.imag)+"i";
        os<<str;
        return os;
    }
 }

Complex Complex::operator+(const Complex & complex)
{
    Complex ans_com;
    ans_com.real = real + complex.real;
    ans_com.imag = imag + complex.imag;
    return ans_com;
}

Complex Complex::operator-(const Complex & complex)
{
    Complex ans_com;
    ans_com.real = this->real - complex.real;
    ans_com.imag = this->imag - complex.imag;
    return ans_com;
}

Complex Complex::operator*(const Complex & complex)  
{
    Complex ans_com;
    ans_com.real = this->real*complex.real - this->imag*complex.imag;
    ans_com.imag = this->real*complex.imag + this->imag*complex.real;
    return ans_com;
}

Complex & Complex::operator~()  //~为单目运算符，无参数
{
   this->imag = -(this->imag);
   return (*this);
}

//friend
Complex operator*(int m, const Complex & complex)
{
    return Complex(m*complex.real, m*complex.imag);
}

// operator=
Complex & Complex::operator=(Complex & complex)
{
    this->real = complex.real;
    this->imag = complex.imag;
    return (*this);
}

bool Complex::operator==(const Complex & complex)
{
    if(this->real == complex.real && this->imag == complex.imag)
    {
        return true;
    }
    else
        return false;
}

bool Complex::operator!=(const Complex & complex)
{
    if((*this)==complex)
        return false;
    else
        return true;
}

//overload operator>>
std::istream & operator>>(std::istream & is, Complex & complex)
{
    is>>complex.real>>complex.imag;
    return is;
}

 