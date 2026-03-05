#pragma once
#include <iostream>
class Rational
{
    private:
        static int id;
        int numerator;
        int denominator;
    public:
    Rational(int n=0, int d=1):numerator(n), denominator(d)
    {
        std::cout<<"Construct_"<<id<<",n:"<<numerator<<",d:"<<denominator<<std::endl;
        id++;
    }
    int getN() const {return numerator;}
    int getD() const {return denominator;}

    friend std::ostream & operator<<(std::ostream& os, const Rational & rhs)
    {
        os<<rhs.numerator<<"/"<<rhs.denominator;
        return os;
    }
    
    Rational operator*(int num)
    {
        return Rational(num*numerator, denominator);
    }

    friend const Rational operator*(int num, const Rational & rat);
    
};

int Rational::id = 1;
const Rational operator*(const Rational & lhs, const Rational & rhs)
{
    return Rational(lhs.getN()*rhs.getN(), lhs.getD()*rhs.getD());
}

// add friend function:int * Rational class
const Rational operator*(int num, const Rational & rat)
{
    return Rational(num*rat.numerator, rat.denominator);
}
