#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	if(open("fichero.txt", O_CREAT, 0645) == -1){
		perror("open");
		return -1;	
	}
	std::cout << "Se ha creado el archivo llamado \"fichero.txt\"" << std::endl;
	return 0;
}
