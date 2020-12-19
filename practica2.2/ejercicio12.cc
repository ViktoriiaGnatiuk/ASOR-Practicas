#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
0 -> entrada estandar

*/
int main(int argc, char* argv[]) {
    int descriptor = open(argv[1], O_CREAT | O_RDWR);
    if(descriptor == -1){
        perror("open");
        return -1;
    }
    int nuevoDescriptor = dup2(descriptor, 0);
	if( nuevoDescriptor == -1){
		perror("dup");
		return -1;	
	}
    return 1;
}
