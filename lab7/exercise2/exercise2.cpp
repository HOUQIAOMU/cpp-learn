#include <iostream>
using namespace std;
template <typename T>
int compare(const T &a, const T &b)
{
    if(a > b)
    {
        return 1; 
    }

    else if(a < b)
    {
        return -1;
    }
    else
    return 0;

}

struct studentinfo
{
    string name;
    int age;
};

//specialization
template<>
int compare<studentinfo>(const studentinfo & a, const studentinfo &b)
{
    if(a.age > b.age)
    {
        return 1; 
    }
    else if(a.age < b.age)
    {
        return -1;
    }
    else return 0;

}
int main()
{
    //1. test for int
    int num1 = 5, num2 = 6;
    int int_result = compare(num1, num2);
    cout<<"Compare of the two integers:"<<int_result<<endl;

    //2.test for float
    float num3 = 5.5f, num4 = 3.6f;
    int float_result = compare(num3, num4);
    cout<<"Compare of the two floats:"<<float_result<<endl;

    //specialization
    studentinfo stu1 = {"tom", 18};
    studentinfo stu2 = {"jerry", 20};
    int spec_result = compare<studentinfo>(stu1,stu2);
    cout<<"Compare of the two structs:"<<spec_result<<endl;
    return 0;

}