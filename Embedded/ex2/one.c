#include "protocol.h"

#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/ipc.h>

int main()
{
    // int fd = shm_open(NAME, O_CREAT | O_EXCL | O_RDWR, 0600);
    int fd = shm_open(NAME, O_EXCL | O_RDWR, 0600);
    if (fd < 0)
    {
        perror("shm_open()");
        return EXIT_FAILURE;
    }
    ftruncate(fd, SIZE);
    int *pointer = (int *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    while (1)
    {
        *pointer += 1;
        sleep(1);
    }
    munmap(pointer, SIZE);
    close(fd);
    return EXIT_SUCCESS;
}
