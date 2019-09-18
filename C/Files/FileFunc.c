#include <stdio.h>
#include <stdlib.h>
#include "FileFunc.h"


void countLetters(char *f_name)
{
 int num,i;
    char c;
    FILE *fp;
    int Bcc[26];  /*big char counter*/
    int Scc[26]; /*small char counter*/
    for(i=0;i<26;i++)
    {
        Bcc[i]=0;
        Scc[i]=0;
    }
    
    if ((fp = fopen(f_name, "r")) != NULL)
    {
		while(!feof(fp))
		{
		    c=getc(fp);
		    if((c>='A')&&(c<='Z'))
		    {
		        Bcc[c-'A']++;
		    }
		    else if((c>='a')&&(c<='z'))
		    {
		        Scc[c-'a']++;
		    }
		}
		for(i=0;i<26;i++)
		{
		    if(Bcc[i]!=0)
		    {
		        printf("the letter %c appears %d times\n", (i + 'A'), Bcc[i]);
		    }
		    if(Scc[i]!=0)
		    {
		        printf("the letter %c appears %d times\n", (i + 'a'), Scc[i]);
		    }
		    
		}
	}
    fclose(fp);
}



void N_line(int n,char *f_name) /*need fix*/
{
	int *LNL; /*last N lines*/
	char c[512];
	int i=0,EndLocation;
	FILE *fp;
	LNL=malloc(n*sizeof(int));
    if ((fp = fopen(f_name, "r")) != NULL)
    {
		fseek(fp,0,2);
		EndLocation=ftell(fp);
		fseek(fp,0,0);

		while(!feof(fp))
		{
			LNL[i%n]=ftell(fp);
			fgets(c,512,fp);
			if(ftell(fp)==EndLocation)
			{
				break;
			}

			i++;
		}
		fseek(fp,0,2);
		EndLocation=ftell(fp);
		fseek(fp,LNL[(i+1%n)],0);
		while(!feof(fp))
		{
			fgets(c,512,fp);
			printf("%s\n",c);
			if(ftell(fp)==EndLocation)
			{
				break;
			}	
		}
		fclose(fp);
		free(LNL);
	}
}



	

