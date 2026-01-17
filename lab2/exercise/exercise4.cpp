#include <iostream>
using namespace std;
int main()
{
    int a,b;
    double c,d,f,g;
    char h;

    a = 19.99+21.99;
    b = (int) 19.99+21.99;
    c = 23/3; //int
    d = 23/3.0; //double
    f = 23/3.0e4;
    g = 23/3.0e5;
    h = 'b'-32;

    //print as the sequence of the picture
    cout<<h<<endl;
    cout<<a<<endl;// 41.98->41
    cout<<b<<endl;//19.99->19 21.99 -> 21
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<g<<endl;
    cout<<f<<endl;

    return 0;
}