#include <stdio.h>
int main()
{
    signed char a = 127; 
    unsigned char b = 0x7f;
    char c = 0x7f; 

    a = a<<1;//01111111 -> 11111110 signed ->-2(signed char:-128-127)
    b = b<<1;//01111111 -> 11111110 unsigned ->254(unsigned char:0-255)
    c = c<<1;// equal to signed char

    printf("a=%d\nb=%d\nc=%d\n",a,b,c);

    a = a>>1;//a = -1,ffffffff
    b = b>>1;//b=127,7f
    c = c>>1;//equal to a
    printf("a=%d\nb=%d\nc=%d\n",a,b,c);
    printf("a=%x\nb=%x\nc=%x\n",a,b,c);
    return 0;
}