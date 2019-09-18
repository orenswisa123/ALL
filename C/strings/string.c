#include <stdio.h>
#include <string.h>
char* my_strcpy(char *s1,char *s2);
char* my_strcat(char *s1,char *s2);
int my_strcmp(char *s1,char *s2);

int main()
{
	char s1[10]="oren";
	char s2[15]="swisa";
	/*printf("%s\n",my_strcpy(s1,s2));*/
	/*printf("%s\n",my_strcat(s1,s2));*/
	printf("%d\n",my_strcmp(s1,s2));
	return 1;
}

char* my_strcpy(char *s1,char *s2)
{
	int i;
	for(i=0;s1[i]!='\0';i++)
	{
		s1[i]=s2[i];
	}
	s1[i]='\0';
	return s1;
}

char* my_strcat(char *s1,char *s2)
{
	int i,j;
	for(i=0;s1[i]!='\0';i++);
	for(j=0;s2[j]!='\0';j++)
	{
	s1[i+j]=s2[j];
	}
	s1[i+j]='\0';
	return s1;
}

int my_strcmp(char *s1,char *s2)
{
	while ( (*s1 != '\0') && (*s1 == *s2) )
	{
    	s1++; 
    	s2++;
   	}
	return *s1-*s2;
}
	




