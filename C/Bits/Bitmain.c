#include<stdio.h>
#include<stdlib.h>
#include "Bit.h"


int main()
{
    BitMap *B1;
    int nf=0,option=0,ans=0,bit=0;
    BitFunc FuncArr[3]={BitOn,BitOff,BitStat};
    B1 = malloc(sizeof(BitMap));
    printf("enter num of fitchers");
    scanf("%d", &nf);
    B1 = Create_BM(nf);

    while (option != -1)
    {
        printf("\n choose option:  \n");
        printf("press 1 to turn on bit \n");
        printf("press 2 to turn off bit \n");
        printf("press 3 to check bit status \n");
        printf("press -1 to exit \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            printf("enter bit number");
            scanf("%d", &bit);
            calculate(FuncArr[0],B1,bit);
        }
        break;
        case 2:
        {
            printf("enter bit number");
            scanf("%d", &bit);
            calculate(FuncArr[1],B1,bit);
        }
        break;
        case 3:
        {
            printf("enter bit number");
            scanf("%d", &bit);
            calculate(FuncArr[2],B1,bit);
        }
        break;
        default:
        break;
        }
     }
     destroy(B1);
}

