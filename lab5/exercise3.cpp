#include <iostream>
#include <stdlib.h>

bool determine( char * first_byte)
{
    if(*first_byte == 0x11)
    {   
        std::cout<<"This is BE"<<std::endl;
        return true;
    }
    else if(*first_byte == 0x44)
    {
        std::cout<<"This is LE"<<std::endl;
        return true;
    }
    else
    return false;
}

int main(int argc, char * argv[])
{
    int numA = 0x11223344;
    if(argc == 2)
    {
        //int * byte = &numA;
        //printf("*byte=%x\n", *byte);
        char * first_byte = (char*)(&numA); //transfer int pointer to char pointer
        printf("first_byte =%x\n", *first_byte );
        determine(first_byte);

        if(argv[1][0] == 'H')
        {
            int * pnumB = (int*)malloc(sizeof(int));
            if(pnumB != NULL)
            {
                
                //printf("*(first_byte+1 = %x\n)", first_byte[1]); output=33;

                //store each byte in numA to pnumB in reverse order.
                char * p_index = (char*)pnumB;
                size_t num_length = sizeof(int);
                for(int i = 0; i<num_length;i++)
                {
                    p_index[i] = first_byte[num_length-1-i]; //逐字节复制
                }
                printf("*pnumB = %x\n", *pnumB);
                free(pnumB);

            }
        }

        else if(argv[1][0] == 'S')
        {
            int numB;
            char * p = (char*)(&numB);
            int * pnumB = (int*)p;
            size_t num_length = sizeof(int);
            for(int i = 0; i<num_length; i++)
            {
                p[i] = first_byte[num_length-1-i]; //
                //printf("*p[%d]=%x\n", i,p[i]);
            }
            printf("*pnumB = %x\n", *pnumB);

            
        }
        
    }


    return 0;
}