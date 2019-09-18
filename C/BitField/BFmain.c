#include <stdio.h>
#include <stdlib.h>
#include "BF.h"

int main()
{
    unsigned int option;
	int cont = 1, result;
	char* string;
	
	while(cont)
	{
		printf("Choose option: \n");
		printf("1: Without bit field option: \n");
		printf("2: With bit field option: \n");
		printf("Any another number - stop\n");
		
		scanf("%x", &option);
		switch(option)
		{
        case 1:
            printf("Enter string to pack: ");
            scanf("%s", string);
            pack(string);

            break;

        case 2:
            printf("Enter string to pack: ");
            scanf("%s", string);
            packfield(string);
            break;
            default:
            cont=0;
            break;
            
        }
    }
            return 0;

}