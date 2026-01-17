#include <iostream>
using namespace std;
int main()
{
    for(size_t n = 2; n>=0; n--)
    {
        cout<<"n="<<n<<" ";
        if(n == 0)
        {
            break;
        }
    }
    return 0;
} 
//size t -> unsigned 
//if transfer to n>0,everything will be ok
//or add if to judge