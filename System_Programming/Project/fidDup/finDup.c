#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include"HashT.h"
#include"md5.h"
#define MD5_DIGEST_LENGTH 16


static void funcDestroyData(void *data);
static void funcDestroyKey(void *key);

typedef struct dirent dirent;


int findDup(char* src)
{
    HASHTBL* HM;
    initialHashTable(&HM);
    destroyelem desKey;
    desKey = funcDestroyKey;
	destroyelem desData=funcDestroyData;
    recReadDirs(src ,HM);
    hashtbl_destroy(HM, desData,desKey);
    return 1;
}



int recReadDirs(char* pathDir,HASHTBL* HM)
{
    DIR *d;
    dirent* dirItems;
    char nextPath[1024];
    char* newPath;
    char* md5buffer;
    unsigned char out[32];
   
    if (pathDir == 0)
    {
        return 0;
    }
    d = opendir(pathDir);
    while (dirItems = readdir(d))
    {
        if(dirItems->d_name[0] != '.' && dirItems->d_type == 8)
        {
            newPath=malloc(2048);
            md5buffer=malloc(1024);
           /* printf("%s/%s\n", pathDir, dirItems->d_name); /* just to check */
            strcpy(newPath , pathDir);
            strcat(newPath, "/");             
            strcat(newPath, dirItems->d_name);
            md5(newPath,out);
            strcpy(md5buffer,out);
            hashtbl_insert(HM, md5buffer, newPath);
        }
        else if(dirItems->d_name[0] != '.' && dirItems->d_type == 4)
        {
            strcpy(nextPath , pathDir);
            strcat(nextPath, "/");             
            strcat(nextPath, dirItems->d_name);
            recReadDirs(nextPath, HM);
        }
    }
    closedir(d);
    return 1;
}
void funcDestroyKey(void *key)
{
	unsigned char* str= (unsigned char*) key;
	
}
void funcDestroyData(void *data)
{
	unsigned char* str= (unsigned char*) data;
	
}

int main()
{
    char ptrDir[]="/home/sqrt15/Desktop/Data/BST";
    /*char* newPath = */findDup(ptrDir);
    /*printf("%s\n", newPath);*/
    return 0;
}