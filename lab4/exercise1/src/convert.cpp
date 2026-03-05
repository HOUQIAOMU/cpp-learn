#include "convert.h"
//convert the number to English words
std::string numberToWords(int num)
{
    std::string ones[] = {"", "one", "two", "three", "four", "five", 
                         "six", "seven", "eight", "nine"};
    std::string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", 
                          "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", 
                         "sixty", "seventy", "eighty", "ninety"};
    std::string result; //record the result

    if(num < 0 || num>999)
    {
        return "out of range(0-999)";
    }

    if(num ==0)
    {
        return "zero";
    }

    if(num>=100)
    {
        int hundred_index;
        hundred_index = num/100;
        result = ones[hundred_index] + " hundred ";

        num = num%100; //update the num to find other
        if(num>0)
        {
            result += "and ";
        }
    }

    if(num >= 20)
    {
        int ten_index;
        ten_index = num/10;
        result += tens[ten_index];
        
        if(num%10>0)
        {
            int num_one = num%10;
            result = result + "-" + ones[num_one];

        }
        return result;
        
    }

    if(num>=10 && num<20)
    {
        int teen_index = num - 10;
        result += teens[teen_index];
        return result;
    }

    if(num>0 && num<10)
    {
        result += ones[num];
    }

    return result;

}

