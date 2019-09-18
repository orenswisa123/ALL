#include <openssl/md5.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<dirent.h>
#include"md5.h"
#include<string.h>
unsigned char* md5(char* filePath,unsigned char* out)
{
    int n;
    MD5_CTX c;
    int fd;
    char buf[512];
    ssize_t bytes;
    strcpy(buf,filePath);
    fd=open(buf,O_RDONLY);
    MD5_Init(&c);
    bytes = read(fd, buf, 512);
    while (bytes > 0)
    {
        MD5_Update(&c, buf, bytes);
        bytes = read(fd, buf, 512);
    }
    MD5_Final(out, &c);
  /*  for (n = 0; n < MD5_DIGEST_LENGTH; n++)
    {
        /*printf("%02x", out[n]);
    }*/
    /*printf("\n");*/
    return out;

}