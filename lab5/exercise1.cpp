#include <iostream>
using namespace std;
int main()
{
    int numbers1[] = {2,4,6,8,10};
    int * p = & numbers1[0];
    int sum = 0;
    cout<<numbers1<<endl; //array name is also a pointer
    cout<<p<<":"<<(*p)<<endl;

    for(int i = 0; i < 5; i++)
    {
        sum += p[i];
        //sum += *(p+i);
    }
    cout<<sum<<endl;

    int numbers2[] = {1,2,3,4,5};
    // &numbers2是整个int[5]数组的地址（类型int (*)[5]），+1偏移整个数组大小（20字节）指向数组末尾后一位，(int*)将数组指针强制转为int*类型，使赋值给int*变量p2合法
    int* p2 = (int*)(&numbers2+1);

    printf("numbers2 = %p\n", numbers2);
    printf("numbers2+4=%p\n", numbers2+4);
    printf("p2 = %p\n", p2);
    printf("*(numbers2+1 = %d\n)", *(numbers2+1));
    printf("p2-1 = %d\n", *(p2-1)); // offset 4 byte(1 int), output is 5;
    return 0;

    //the output i guess
    /*
    num2.address
    num2[4].address
    num2[5].address(out of rage)
    2
    1 wrong! is 5

    */




}