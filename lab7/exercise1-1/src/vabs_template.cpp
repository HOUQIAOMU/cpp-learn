#include <iostream>

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

int main()
{
    int *p0 = new int[5]{-1,-2,3,4,-5};
    vabs(p0,5);
    for(int i = 0;i<5;i++)
    {
        std::cout<<p0[i]<<std::endl;
    }
    delete [] p0;

    float *p1 = new float[5]{-1.5f, -2.3f, 3.7f, 4.1f, -5.9f};
    vabs(p1,5);
     for(int i = 0;i<5;i++)
    {
        std::cout<<p1[i]<<std::endl;
    }
    delete [] p1;

    double p3[] = {-1.5, -2.3, 3.7, 4.1, -5.9};
    vabs(p3, 5);
    std::cout << "Double array: ";
    for(int i = 0; i < 5; i++) std::cout << p3[i] << " ";
    std::cout << std::endl;
}