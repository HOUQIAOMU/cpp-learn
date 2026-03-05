#include <iostream>
#include "convert.h"

int main()
{
    std::cout<<"Transfer number to words"<<std::endl;
    std::cout<<"========================"<<std::endl;

    int test_numbers[] = {0,5,12,25,100,121,124,555,998};
    for(int i = 0; i<(sizeof(test_numbers)/sizeof(test_numbers[0]));i++)
    {
        std::cout<<"No"<<i+1<<".  "<<test_numbers[i]<<"->"<<numberToWords(test_numbers[i])<<std::endl;
        
    }
    return 0;
}