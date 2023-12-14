#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4096

int main() {
    char *shared_memory = (char *)mmap(NULL, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    printf("Child reads: %s\n", shared_memory);

    munmap(shared_memory, SIZE);

    return 0;
}
