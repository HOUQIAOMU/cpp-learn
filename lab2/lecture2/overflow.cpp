#include <iostream>
using namespace std;

//1.learn the overflow of int;
//2.and learn "sizeof"
//3.also use this file to learn gdb
int main()
{
    int a = 56789;
    int b = 56789;
    int c = a*b;
    cout<<"a*b = "<< c <<endl;
    

    //correct version
    unsigned int a1 = 56789;
    unsigned int a2 = 56789;
    unsigned int c1 = a1*a2;
    cout<< "a*b="<<c1<<endl;
    cout<<"sizeof(int)"<<sizeof(int)<<endl;
    return 0;
    
}

// result:a*b = -1069976775
// wrong! because of ox(hex)