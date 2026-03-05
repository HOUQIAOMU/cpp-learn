#include <iostream>
#include <memory>
int main()
{
    // double * p_reg = new double(5);
    // std::shared_ptr<double> pd;
    // pd = std::shared_ptr<double>(p_reg);
    // std::cout<<p_reg<<"*p_reg="<<*p_reg<<std::endl;
    // std::cout<<pd<<"*pd="<<*pd<<std::endl;
    // //这样写其实不好,pd 接管了 p_reg 指向的内存，当 pd 析构时会自动 delete 这块内存；但 p_reg 依然是一个普通指针，指向的内存被释放后就变成野指针
    // //正常应该先定义pd，然后令double * p_reg = pd.get()
    // //但是一般还是不做智能指针和正常指针间的转换

    // std::shared_ptr<double>p_shared(p_reg);
    // std::cout<<p_shared<<"p_shared="<<*p_shared<<std::endl;
    /*
    报错核心逻辑：
shared_ptr 的 “引用计数” 只在同一个 shared_ptr 家族内生效（比如 pd 拷贝给 p_shared 才会共享计数），但你是用同一个原始指针分别创建了两个独立的 shared_ptr（pd 和 p_shared），这两个 shared_ptr 互相不知道对方的存在，都认为自己是这块内存的 “唯一管理者”，于是析构时各自执行一次 delete，导致双重释放。
3. 验证：如果是合法的 shared_ptr 拷贝，就不会出错
如果把 std::shared_ptr<double>p_shared(p_reg); 改成 std::shared_ptr<double>p_shared(pd);（拷贝 pd），就不会崩溃 —— 因为此时 pd 和 p_shared 共享引用计数（计数变为 2），析构时：
析构 p_shared：引用计数减为 1，不释放内存；
析构 pd：引用计数减为 0，释放内存；
全程只释放一次，完全安全。
    */

    /*--------------我认为正确的写法----------------*/
    std::shared_ptr<double> p_d(new double(5));
    std::shared_ptr<double> p_shared;
    p_shared = p_d;
    double * p_reg = p_d.get();
    std::cout<<p_reg<<",*p_reg="<<*p_reg<<std::endl;
    std::cout<<p_d<<",*pd="<<*p_d<<std::endl;
    std::cout<<p_shared<<",p_shared="<<*p_shared<<std::endl;


    /*---------------next part--------------------*/
    /*
    std::string str = "Hello,world!";
    std::shared_ptr<std::string> pstr(&str);
    */
    //这个写法问题非常大，相当于用delete释放栈内存，这是不合法的！
    std::shared_ptr<std::string> pstr(new std::string("Hello,world!"));
    //或者写：
    std::shared_ptr<std::string> pstr2 = std::make_shared<std::string>("Hello,c++");
    std::shared_ptr<std::string> pstr3 = pstr2;
    std::cout<<pstr<<",*pstr="<<*pstr<<std::endl;
    std::cout<<pstr2<<",*pstr2="<<*pstr2<<std::endl;
    std::cout<<pstr3<<",*pstr3="<<*pstr3<<std::endl;


    return 0;

}