#include <iostream>
using namespace std;

class ConstMember
{
    private:
        const int m_a;
    public:
        //constructor
        ConstMember(int a):m_a(a){} //const变量必须在创建的那一刻就被初始化。等价于m_a = a,构造函数里面是空的

        void display() const{
            cout<<"The value of the const member variable m_a is:"<<m_a<<endl;
        }
};

int main()
{
    ConstMember o1(666);
    ConstMember o2(66);
    o1.display();
    o2.display();
    // o1 = o2;
    //当你写 o1 = o2; 时，本质是调用 C++ 为类默认生成的赋值运算符重载函数（operator=），这个默认函数的逻辑是：把 o2 的所有成员变量的值，逐一赋值给 o1 的对应成员变量。
    //但你的类里有 const int m_a —— const 变量的特性是一旦初始化就不能被修改，默认赋值运算符试图给 o1.m_a 赋 o2.m_a 的值，这就违反了 const 的规则，所以编译器会直接报错。

    return 0;
}
