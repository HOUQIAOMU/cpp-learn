#include <iostream>
#include <memory>
class B;

class A
{
    public:
        std::shared_ptr<B> pb;
        A(){ std::cout << "Constructor:A()" << std::endl;}
        ~A(){ std::cout << "Destructor:A()" << std::endl;}
};

class B
{
    public:
        //std::shared_ptr<A> pa;
        std::weak_ptr<A> pa;
        B(){ std::cout << "Constructor:B()" << std::endl;}
        ~B(){ std::cout << "Destructor:B()" << std::endl;}
};
//解决循环引用的方法：将一个成员的变量改为weak_ptr
//weak_ptr是弱引用，它不增加对象的引用计数，在循环引用场景下，对象可以正常释放，而不像shared_ptr一样，需要对象没有被引用才能被释放。

int main()
{
    std::shared_ptr<A> spa = std::make_shared<A>();
    std::shared_ptr<B> spb = std::make_shared<B>();
    spa->pb = spb;
    spb->pa = spa;
    //这个情况就是一个循环引用，A在等着B释放，但B又在等着A释放
    //从而导致都无法及时释放，内存无法回收

    //将B的成员变量一个改为weak_ptr后，A
    //析构时，spb先析构，但此时还有B还有一个spa->pb指向B,B无法完全释放.再之后spa析构，A的引用从1->0，A释放。A释放后，B的引用从1->0，B释放。
    return 0;
}