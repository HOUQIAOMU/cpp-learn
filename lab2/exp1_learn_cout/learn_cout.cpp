#include <iostream>
using namespace std;
int main()
{
    //1.cout.precision
    cout.precision(5); 
    cout<<356.789<<endl;
    

    //2.cout.width(len)
    cout.width(12);
    cout<<456.77<<endl;
    
    //3.cout.fill('+')
    cout.width(8);
    cout.fill('+');
    cout<<456.77<<endl;
    return 0;
    // print:++456.77
}