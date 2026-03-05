// rational.h
#pragma once
#include <iostream>
class Rational
{
    private:
        static int id;
        int numerator;
        int denominator;
    public:
        Rational(int n = 0, int d = 1):numerator(n), denominator(d)
        {
            std::cout<<"Construct_"<<id<<", n:"<<numerator<<", d:"<<denominator<<std::endl;
            id++;
        }
        int getN() const {return numerator;}
        int getD() const {return denominator;}

        friend std::ostream & operator<<(std::ostream& os, const Rational & rhs)
        {
            os<<rhs.numerator<<"/"<<rhs.denominator;
            return os;
        }
        friend const Rational operator*(const Rational & lhs, const Rational & rhs); //use friend function to overload *

};

int Rational::id = 1;
const Rational operator*(const Rational & lhs, const Rational & rhs)
// friend function definition
{
    return Rational(lhs.numerator*rhs.numerator, lhs.denominator*rhs.denominator);
}

