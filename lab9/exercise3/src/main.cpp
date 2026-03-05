#include <iostream>
#include "complex.hpp"
using namespace std;
int main()
{
    Complex c1(2,3);
    c1.display();
    Complex c2(4,-5);
    c2.display();
    Complex add = c1.add(c2);
    cout<<"----after add----"<<endl;
    add.display();
    Complex sub = c1.subtract(c2);
    cout<<"----after sub----"<<endl;
    sub.display();
}