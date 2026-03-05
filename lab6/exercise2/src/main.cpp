#include <iostream>
using namespace std;
#include <swap.hpp>

int main()
{
    int i = 35;
    int j = 30;
    printf("i=%d, j=%d\n", i,j);
    swap(i,j);
    cout<<"-----swap-----"<<endl;
    printf("i=%d, j=%d\n", i,j);
    return 0;
    
}