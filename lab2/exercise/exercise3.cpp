#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout<<fixed; // Floating-point output should be displayed in fixed-point or decimal notation. 
    // in commen situation,keep 6 point,so its output is 1.000000;
    float f1 = 1.0f;
    cout<<"f1="<<f1<<endl;
    
    float a = 0.1f;
    float f2 = a+a+a+a+a+a+a+a+a+a;
    cout<<"f2="<<f2<<endl;

    if(f1==f2)
    {
        cout<<"f1=f2"<<endl;
    }
    else
        cout<<"f1!=f2"<<endl;
    

    cout<<"-----------"<<endl;
    // use error limit
    if(fabs(f1-f2)<1e-6)
    {
        cout<<"f1=f2"<<endl;
    }
    else
        cout<<"f1!=f2"<<endl;
    return 0;


}