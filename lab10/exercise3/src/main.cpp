#include <iostream>
#include "lab10/exercise3/include/complex.hpp"


int main()
 {
    Complex a(3,4);
    Complex b(2,6);
    std::cout<<"a="<<a<<std::endl;
    std::cout<<"b="<<b<<std::endl;
    std::cout<<"~b="<<~b<<std::endl;
    std::cout<<"a+b="<<(a+b)<<std::endl;
    std::cout<<"a-b="<<(a-b)<<std::endl;
    std::cout<<"a-2="<<(a-2)<<std::endl;
    std::cout<<"a*b="<<(a*b)<<std::endl;
    std::cout<<"2*a="<<(2*a)<<std::endl;
    std::cout<<"============================="<<std::endl;

    Complex c = b;
    std::cout<<"c="<<c<<std::endl;
    std::cout<<std::boolalpha; //让bool量输出变为true和false
    std::cout<<"b==c? "<<(b==c)<<std::endl;
    std::cout<<"b!=c? "<<(b!=c)<<std::endl;
    std::cout<<"a==b? "<<(a==b)<<std::endl;

    Complex d;
    std::cout<<"Please enter the real and the imag of d"<<std::endl;
    std::cin>>d;
    std::cout<<"Before assignment, d="<<d<<std::endl;
    d = c;
    std::cout<<"After assignment, d="<<d<<std::endl;
    return 0;

 }