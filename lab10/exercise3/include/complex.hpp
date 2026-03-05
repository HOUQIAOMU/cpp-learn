#pragma once
#ifndef __COMPLEX_HPP
#define __COMPLEX_HPP
#include <iostream>
class Complex
{
    private:
        int real;
        int imag;
    public:
    // 1.constructor function
    Complex(int re = 0, int im = 0):real(re), imag(im)
    {
        //std::cout<<"Complex "<<real<<"+("<<imag<<")"<<"i"<<std::endl;
    }

    // 2. operator<<
    friend std::ostream & operator<<(std::ostream & os, const Complex & complex);

    // 3. opertor+ 
    //example: a+b
    Complex operator+(const Complex & complex);

    // 4. operator- 
    //example: a-b
    Complex operator-(const Complex & complex);

    // 5.opeartor*
    Complex operator*(const Complex & complex);

    //6. friend opeartor*
    friend Complex operator*(int m, const Complex & complex);

    //7.operator~
    Complex & operator~() ;

    //8.operator=
    Complex & operator=(Complex & complex);

    //9.operator==
    bool operator==(const Complex & complex);

    //10.operator!=
    bool operator!=(const Complex & complex);

    //11.operator>>
    friend std::istream & operator>>(std::istream & is,Complex & complex);



};




#endif