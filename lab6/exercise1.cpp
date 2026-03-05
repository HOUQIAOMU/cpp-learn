#include <iostream>
using namespace std;

int * create_array(int size)
{
    // 需要动态分配堆内存创建数组（避免函数结束后栈内存被释放）
    // 堆内存生命周期由程序员控制，需配合delete[]释放

    // int arr[size]; 
    // for(int i = 0; i<size; i++)
    // {
    //     arr[i] = i* 10;
    // }
    int * arr = new int[size];
    for(int i = 0; i<size; i++)
    {
        arr[i] = i*10;
    }
    return arr;
}

int main()
{
    int len = 16;
    int * ptr = create_array(len);
    for(int i = 0; i<len; i++)
    {
        cout<<ptr[i]<<endl;
    }
    
    delete[] ptr;
    return 0;
}