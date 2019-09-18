#include <stdio.h>
#include <ctype.h>
#include <string.h>

int Find_Int(char*);
char* Find_name(char*);

int main(int argc,char* argv[])
{
	int i,age;
	char *name=NULL;
	if(!argc==3)
	{
		printf("Error");
		return 0;
	}
	else
	{	
		age=Find_Int(argv[1]);
		if(age==0)
		{
			age=Find_Int(argv[2]);
		}
		name=Find_name(argv[1]);
		if(name==NULL)
		{
			name=Find_name(argv[2]);	
		}
	}
	if(age==0||name==NULL)
	{
		printf("Error");
		return 0;
	}
	else	
		printf("%s " "%d\n",name,age);
		return 1;
}

int Find_Int(char* str)
{
	int i,ans=0;
	for(i=0;i<strlen(str)-1;i++)
	{
		if(!(isdigit(str[i])))
		{
			ans=0;
			break;
		}
	}
	ans=atoi(str);
	return ans;
}
char* Find_name(char* str)
{
	int i;
	static char *name=NULL;
	for(i=0;i<strlen(str);i++)
	{
		if(!(isalpha(str[i])))
		{
			name=NULL;
			return name;
		}
	}
	return str;
}



		
	
	
	
	
