#ifndef __VABS_TEMPLATE_HPP
#define __VABS_TEMPLATE_HPP
#include <iostream>

//有函数模板，推荐直接把定义写到hpp文件中
template<typename T>
bool vabs(T* p, int n)
{
    // 检查指针和数组长度
    if(p == nullptr || n <= 0)
    {
        std::cout << "Pointer is null or n is invalid" << std::endl;
        return false;
    }

    // 计算绝对值
    for(int i = 0; i < n; i++)
    {
        p[i] = std::abs(p[i]);  // std::abs 支持所有数值类型
    }
    return true;
}
#endif