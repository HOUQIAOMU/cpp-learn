#include <stdio.h>

int add1(int a, int b)
{
    int sum = (a++)+(b++);
    return sum;
}

int add2(int *x, int *y)
{
    int sum = ((*x)++) + ((*y)++);
    return sum;
}

int add3(int &c, int &d)
{
    int sum = (c++) + (d++);
    return sum;
}

int main()
{
    int i = 0, j = 0;
    scanf("%d", &i);
    scanf("%d", &j);
    printf("i_address:%p, j_address:%p\n", &i, &j);

    int sum1 = add1(i,j);
    printf("%d+%d=%d\n", i,j,sum1);

    int * p1 = &i;
    int * p2 = &j;
    int sum2 = add2(p1,p2);
    printf("i=%d, j=%d, sum2=%d\n", i,j,sum2);// i and j has been changed because of pointer, but still follow "pass by value".

    int sum3 = add3(i,j); // use reference in c++
    printf("%d+%d = %d\n", i,j,sum3); //output sum3 = 5; i=3, j=4;
    // i and j has been changed because of references.

    
    return 0;
}