#include <stdio.h>
#include <string.h>
#include <math.h>

char* func_Int2Bin(int ,char*);
int func_Bin2Int(char* );
char* squeeze(char *,char *);
int location(char *,char *);

int main()
{
	int cont=1;
	int option=0;
	int num1=0;
	int dec=0;
	char binary[14];
	char binary2[]={"10101"};	
	char s1[]="ABCDEF";
	char s2[]="BKE";
	char s3[]="CD";
	while(cont)
	{
		printf("\n");
		printf("Choose option: \n");
		printf("1: Int2Bin  \n");
		printf("2:Bin2Int    \n");
		printf("3: Squeeze  \n");
		printf("4: Location  \n");
		printf("Any another number - stop \n");
		scanf("%d", &option);

		switch (option)
		{

			case 1:
				printf("enter decimal number:");
				scanf("%d",&num1);
				func_Int2Bin(num1,binary);
			break;
		
			case 2:	
				dec=func_Bin2Int(binary2);
				printf("%d",dec);
			break;
		
			case 3:
				printf("%s\n",squeeze(s1,s2));
			break;
		
			case 4:
				printf("%d",location(s1,s3));
			break;
		
			default:
				cont=0;
			break;
		}
	}

}

char* func_Int2Bin(int num,char* binary)
{
	int j=0,i=0;
	for(j=0;binary[j]!='\0';j++)
		binary[j]=0;
	while(num>0)    
	{    
		binary[i]=num%2+48;    
		num=num/2; 
		i++;   
	}   
	for(i=(strlen(binary)-1);i>=0;i--)
		printf("%c",binary[i]);
	printf("\n");
	return binary;

}

int func_Bin2Int(char* s1)
{
	int bin_num=atoi(s1);
    	int decimalNumber = 0, i = 0,remainder,base=1;
    	while (bin_num!=0)
    {
        remainder = bin_num%10;
        bin_num /= 10;
        decimalNumber += remainder*base;
	base=base*2;
        ++i;
    }
    return decimalNumber;
}
	

char* squeeze(char *s1,char *s2)
{
	int i,j,k;
	for(i=0;s2[i]!='\0';i++)
	{
		for(j=0;s1[j]!='\0';j++)
		{
			if(s2[i]==s1[j])
			{
				for(k=j;s1[k]!='\0';k++)
				{
				s1[k]=s1[k+1];
				}
			}
		}
	}
	return s1;
}





int location(char *s1,char *s2)
{
	int i,j,ans=-1;
	for(i=0;s2[i]!='\0';i++)
	{
		for(j=0;s1[j]!='\0';j++)
		{
			if(s2[i]==s1[j])
			{
				ans=j;
				while(s2[i]!='\0')
				{
					if(s2[i]!=s1[j])
					{
						ans=-1;
					}
					i++;
					j++;
				}
				return ans;
			}
		}
	}
}
		
