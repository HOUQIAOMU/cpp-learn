#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__

#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
class Calculator {
  private:
    std::string expression;
    double numa;
    double numb;
    char op;
    bool valid = false;

    bool find_Calculator_member(std::string & expr)
    //此函数要提取出输入的linux命令中的运算符以及两个数字。
    {
      expr.erase(std::remove_if(expr.begin(), expr.end(), ::isspace), expr.end()); // 移除空格
      if (expr.empty())
      {
        std::cerr << "Error: Empty expression!" << std::endl;
        return false; // Return or handle as needed
      }
      bool numa_exist = false;
      std::string numa_str;
      std::string numb_str;
      int operator_pos = -1;
      bool find_operator = false;
      

      //------------1.寻找运算符----------------//
        for(int i = 0; i<expr.length();i++)
        {
          //如果第一个是字符，那是和数字一起的，不太对，所以继续往下找
          if(i == 0 && (expr[i] == '-' || expr[i] == '+')) //如果第一个字符是负号或者正号，则继续往下找
          {
            continue;
          }
          
          
          else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
          {
            operator_pos = i;
            op = expr[i];
            find_operator = true;
            break;
          }
                   
        }

        if(!find_operator)
        {
          std::cerr << "Error: No operator found!" << std::endl;
          return false; // Return or handle as needed
        }

        // ------------2.寻找numa------------------//
        for(int i = 0; i<operator_pos;i++)
        {
          if(isdigit(expr[i]) || expr[i] == '.' || (i == 0 && (expr[i] == '-' || expr[i] == '+'))) //如果是数字或者小数点，或者第一个字符是负号或者正号，则继续往下找
          {
            numa_str += expr[i];
            
          }
          else
          {
            std::cerr << "Error: Invalid character in first number!" << std::endl;
            return false; // Return or handle as needed
          }
        }

        //------------3.寻找numb------------------//
        for(int i = operator_pos + 1; i < expr.length(); i++)
        {
          if(isdigit(expr[i]) || expr[i] == '.' || (i == operator_pos + 1 && (expr[i] == '-' || expr[i] == '+'))) //如果是数字或者小数点，或者第一个字符是负号或者正号，则继续往下找
          {
            numb_str += expr[i];
            
          }
          else
          {
            std::cerr << "Error: Invalid character in second number!" << std::endl;
            return false; // Return or handle as needed
          }
        }

        if(numa_str.empty() || numb_str.empty())
        {
          std::cerr << "Error: Missing number!" << std::endl;
          return false; // Return or handle as needed
        }
        numa = std::stod(numa_str);
        numb = std::stod(numb_str); 
        return true;
    }

  public:
    Calculator(const char *expr):expression(expr){
      valid = find_Calculator_member(expression);
      if(!valid)
      {
        std::cerr << "Wrong expression!" << std::endl;
        // Handle as needed, e.g., throw an exception or set default values
      }
    }

    double calculate() {
        switch (op) {
            case '+':
                return numa + numb;
            case '-':
                return numa - numb;
            case '*':
                return numa * numb;
            case '/':
                if (numb != 0) {
                    return numa / numb;
                } else {
                    std::cerr << "Error: Division by zero!" << std::endl;
                    return 0; // Return 0 or handle as needed
                }
            default:
                std::cerr << "Error: Invalid operator!" << std::endl;
                return 0; // Return 0 or handle as needed
        }
    }

    void print_result() {
      if(!valid)
      {
        return;
      }
      double result = calculate();
      std::cout << numa << op << numb << "=" << result << std::endl;
    }
    

};

#endif

