#include <iostream>

int main()
{
    // once auto type has been settled,it won't change like python.
    auto a = 10; // auto -> int
    a = 20.5;// in fact, a = 20;
    a += 10.5;// int(20+10.5) = 30
    std::cout<<a<<std::endl;

    auto b = 10.0; //auto -> double
    b = 20.5;
    b+=a;
    std::cout<<b<<std::endl;
    return 0;

}