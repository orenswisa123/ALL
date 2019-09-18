#include <stdio.h>
#include <stdlib.h>
#include "FileFunc.h"

void N_line(int,char*);

int main()
{
	int option=0;
	int NOL=0; /*num of lines*/
	char f_name[32];
	while(option!=-1)
	{
		printf("press 1 for last N lines function \n");
        printf("press 2 for Letter counter \n");
        printf("press 3 for Word counter \n");
        scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("enter name of file: \n");
				scanf("%s",f_name);
				printf("enter number of lines: \n");
				scanf("%d",&NOL);
				N_line(NOL,f_name);
				break;
			case 2:
				printf("enter name of file: \n");
				scanf("%s",f_name);
				countLetters(f_name);
				break;
			default: 
		        break;
		}
	}
    return 0;
}
