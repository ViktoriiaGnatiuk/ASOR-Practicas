#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argv, char *argc[])
{
    char const * const FIFO_PATH = "my_pipe2";
    if(mkfifo(FIFO_PATH, 0777) == -1){
        perror("mkfifo");
        return -1;
    }else{
        std::cout << "Se ha creado la tubería" << std::endl;
        int fd = open(FIFO_PATH, O_WRONLY);
		write(fd, argc[1], strlen(argc[1]));
		close(fd);
    }
    return 0;
}
