#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char description[1024];
}Stu;

void disp_struct(Stu * stud)
{
    printf("student_id:%d\t, student_info:%s\n", stud->id, stud->description);
}


int main()
{
    // Stu stu = {3,"NAZHA"};
    // Stu * stum = &stu;
    // disp_struct(stum);
    
    // use heap
    Stu * stum_heap = (Stu *)malloc(sizeof(Stu));
    stum_heap -> id = 3;
    strcpy(stum_heap->description, "NAZHA");
    disp_struct(stum_heap);





    return 0;

}