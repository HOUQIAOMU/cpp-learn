#include <iostream>
#include "add.h"
int main()
{
    int num1 = 2147483647;
    int num2 = 1;
    int num3 = 0;
    
    int result = add(num2,num3);
    std::cout<<"the result is "<<result<<std::endl;
    return 0;
}
/*
mainly learn:
    compile and link:
    1.use "g++ -c main.cpp -o main.o" to compile and generate .o file(add.cpp the same)
    2. use "g++ main.o add.o -o exercise2" to link 2 files
    3."./exercise2" to run
    or use only 1 command:
    "g++ main.cpp add.cpp -o exercise2"
    but in huge programme ,mostly use part compile and link
    and also,use makefile or cmake to get convenience. 
*/