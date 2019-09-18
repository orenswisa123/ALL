#include <openssl/md5.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<dirent.h>
#include"md5.h"
#include<string.h>
unsigned char* md5(char* filePath)
{
    int n;
    FILE *f;
    MD5_CTX c;
    char buf[512];
    ssize_t bytes;
    unsigned char out[MD5_DIGEST_LENGTH];
    f=fopen(filePath,"r");
    MD5_Init(&c);
    bytes = read(fileno(f), buf, 512);
    while (bytes > 0)
    {
        MD5_Update(&c, buf, bytes);
        bytes = read(fileno(f), buf, 512);
    }
    MD5_Final(out, &c);
    for (n = 0; n < MD5_DIGEST_LENGTH; n++)
    {
        printf("%02x", out[n]);
    }
    printf("\n");
    fclose(f);
    return out;

}
