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
    char *const parmList[] = {argc[1], argc[2], argc[3], argc[4], NULL};
    char *const envParms[2] = {"STEPLIB=SASC.V6.LINKLIB", NULL};
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
            execve("/u/userid/bin/newShell", parmList, envParms);
        break;
        case 1:
            //Padre
            dup2(fd[PIPE_W], 1);
            close(fd[PIPE_R]);
            execve("/u/userid/bin/newShell", parmList, envParms);
        break;
    }
    return 0;
}
