#ifndef __COMPLEX_HPP
#define __COMPLEX_HPP
#include <iostream>
class Complex
{
    private:
        const double real; //实部
        const double imag; //虚部
        
    public:
    
    Complex(double num_real, double num_imag):real(num_real),imag(num_imag){}

    // 1.add function
    Complex add(Complex & add_complex) const;

    // 2.subtract function
    Complex subtract(Complex & sub_complex) const;
    
    // 3.display the complex
    void display() const;
   
};
#endif