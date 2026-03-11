#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__

#include <iostream>
class Calculator {
  private:
    double numa;
    double numb;
    char operator;
    std::string expression;
    void find_Calculator_member()
    //此函数要提取出输入的linux命令中的运算符以及两个数字。
    {
        //1.提取运算符
        bool find_operator = false;
        int operator_position = -1;
        for(int i = 0; i < expression.length(); i++)
        {
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
            {
                
                if(i == 0 &&(expression[i] == '+' || expression[i] == '-'))
                {
                    // 处理第一位情况
                    continue;
                }
                operator = expression[i];
                operator_position = i;
                find_operator = true;
                break;
            }
        }
        if(!find_operator) //防止找不到运算符情况
        {
            std::cerr << "Error: Invalid expression!" << std::endl;
            return;
        }
        if(operator_position == expression.length() - 1) //防止运算符在最后一位情况
        {
            std::cerr << "Error: Invalid expression!" << std::endl;
            return;
        }

        // //2.提取numa
        // for(int i = 0; i< operator_position; i++)
        // {
        //     if(expression[i] >= '0' && expression[i] <= '9' || expression[i] == '.')
        //     {
        //         std::string numa_str += expression[i];
        //     }
        //     else
        //     {
        //         std::cerr << "Error: Invalid character in first number!" << std::endl;
        //         return;
        //     }
        // }
        

        
    }
  public:
    // Calculator(double a, double b) : numa(a), numb(b) {}
    // double calculate() {
    //     switch (operator) {
    //         case '+':
    //             return numa + numb;
    //         case '-':
    //             return numa - numb;
    //         case '*':
    //             return numa * numb;
    //         case '/':
    //             if (numb != 0) {
    //                 return numa / numb;
    //             } else {
    //                 std::cerr << "Error: Division by zero!" << std::endl;
    //                 return 0; // Return 0 or handle as needed
    //             }
    //         default:
    //             std::cerr << "Error: Invalid operator!" << std::endl;
    //             return 0; // Return 0 or handle as needed
    //     }
    // }

    // bool 

    void display_operator(
        std::cout << "Operator: " << operator << std::endl;
    )

};

