#include <iostream>
#include <string.h>
using namespace std;
struct stu
{
    int id;
    char description[1024];
};

void disp_struct(stu & student)
{
    cout<<"Student_id:"<<student.id<<","<<"Student_info:"<<student.description<<endl;
}

void disp_struct_pointer(stu * stu)
{
    cout<<"Student_id:"<<stu->id<<","<<"Student_info:"<<stu->description<<endl;
}

int main()
{
    stu stud = {3,"NAZHA"};
    disp_struct(stud);

    stu * stup = new stu;
    stup->id = 5;
    strcpy(stup->description, "REBA");
    disp_struct_pointer(stup);


    return 0;
}
