#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define PIPE_W 1
#define PIPE_R 0
int main(int argv, char *argc[])
{
    if (argv < 2) {
        std::cout << "No se ha introducido el comando" << std::endl;
        return -1;
    }
    int fd[2];
    int p = pipe(fd);
    int f = fork();
    switch(f)
    {
        case -1:
            perror("fork");
            return -1;
        break;
        case 0:
            //Hijo
            dup2(fd[PIPE_R], 0);
            close(fd[PIPE_W]);
            close(fd[PIPE_R]);
            execlp(argc[3],argc[3],argc[4], (char*)NULL);
        break;
        case 1:
            //Padre
            dup2(fd[PIPE_W], 1);
            close(fd[PIPE_W]);
            close(fd[PIPE_R]);
            execlp(argc[1],argc[1],argc[2], (char*)NULL);
        break;
    }
    return 0;
}
