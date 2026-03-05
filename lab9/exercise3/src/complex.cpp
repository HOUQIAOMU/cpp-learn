#include <iostream>
using namespace std;
#include "complex.hpp"

// class Complex
// {
//     private:
//         const double real; //实部
//         const double imag; //虚部
        
//     public:
    
//     Complex(double num_real, double num_imag):real(num_real),imag(num_imag){}

//     // 1.add function
//     Complex add(Complex & add_complex) const;

//     // 2.subtract function
//     Complex subtract(Complex & sub_complex) const;
    
//     // 3.display the complex
//     void display() const;
    
// };

Complex Complex::add(Complex & add_complex) const
{
    double add_real_result = real + add_complex.real;
    double add_imag_result = imag + add_complex.imag;
    Complex add_result(add_real_result, add_imag_result);
    return add_result;
}

Complex Complex::subtract(Complex & sub_complex) const
{
    double sub_real_result = real - sub_complex.real;
    double sub_imag_result = imag - sub_complex.imag;
    Complex add_result(sub_real_result, sub_imag_result);
    return add_result;
}

void Complex::display() const
{
    if(imag>=0)
        printf("The complex is %.2f+%.2fi\n", real, imag);
        else
        printf("The complex is %.2f%.2fi\n", real, imag);
}

