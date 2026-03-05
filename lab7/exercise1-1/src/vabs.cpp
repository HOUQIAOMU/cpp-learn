#include <iostream>

bool vabs (int *p, int n)
{
    if(p == NULL || n<=0)
    {
        std::cout<<"This pointer is null or input n is wrong"<<std::endl;
        return false;
    }

    // *p points to the array, n is the element number
    for(int i = 0; i<n; i++)
    {
        p[i] = std::abs(p[i]);
    }
    return true;
}

bool vabs (float *p, int n)
{
    if(p == NULL || n<=0)
    {
        std::cout<<"This pointer is null or input n is wrong"<<std::endl;
        return false;
    }

    // *p points to the array, n is the element number
    for(int i = 0; i<n; i++)
    {
        p[i] = std::abs(p[i]);
    }
    return true;
}

bool vabs (double *p, int n)
{
    if(p == NULL || n<=0)
    {
        std::cout<<"This pointer is null or input n is wrong"<<std::endl;
        return false;
    }

    // *p points to the array, n is the element number
    for(int i = 0; i<n; i++)
    {
        p[i] = std::abs(p[i]);
    }
    return true;
}
