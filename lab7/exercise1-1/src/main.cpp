#include <iostream>
#include "vabs.hpp"


int main()
{
    //函数指针
    bool (* int_fptr)(int*, int) = vabs;
    bool (* float_fptr)(float*, int) = vabs;
    bool (* double_fptr)(double*, int) = vabs;

    int *p0 = new int[5]{-1,-2,3,4,-5};
    vabs(p0,5);
    for(int i = 0;i<5;i++)
    {
        std::cout<<p0[i]<<std::endl;
    }
    std::cout<<"int:"<<(void*)(int_fptr)<<std::endl;
    delete [] p0;

    float *p1 = new float[5]{-1.5f, -2.3f, 3.7f, 4.1f, -5.9f};
    vabs(p1,5);
     for(int i = 0;i<5;i++)
    {
        std::cout<<p1[i]<<std::endl;
    }
    std::cout<<"float:"<<(void*)(float_fptr)<<std::endl;
    delete [] p1;

    double p3[] = {-1.5, -2.3, 3.7, 4.1, -5.9};
    vabs(p3, 5);
    std::cout << "Double array: ";
    for(int i = 0; i < 5; i++) 
    std::cout << p3[i] << " ";
    std::cout << std::endl;
    std::cout<<"double:"<<(void*)(double_fptr)<<std::endl;

    return 0;
    
}