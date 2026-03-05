#include <iostream>
using namespace std;

int main()
{
    int matrix[][4] = {1,3,5,7,9,11,13,15,17,19};
    int * p = *(matrix+1); // use * to match type
    cout<<p<<":"<<(*p)<<endl; //*p output is 9;
    cout<<matrix<<":"<<*matrix<<endl;
    cout<<matrix+1<<":"<<*(matrix+1)<<endl;

    p+=3;
    cout<<"*p++ = "<< *p++ <<endl;

    const char *str = "welcome to programming";
    cout<<"*str = "<< *str<<endl;
    long * q = (long *)str;
    cout<<"*q="<<*q<<endl; //*q 不是地址，而是顺着 q 存储的地址读取到的 long 类型整数（多个字符 ASCII 码拼接的无意义值）。
    q++;
    char * r = (char*)q;
    cout<<*r<<endl;
    cout<<r<<endl;

    



    /*these are equal
    // 你写的写法
    int * p = *(matrix+1);

    // 等价写法1：用数组下标代替指针算术（更易读）
    int * p = matrix[1];

    // 等价写法2：直接取第1行第0列的地址（最直观）
    int * p = &matrix[1][0];
    */
   return 0;
}