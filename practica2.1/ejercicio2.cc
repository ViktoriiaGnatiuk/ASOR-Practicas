#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
int main() {
	int respuesta=setuid(0);
	if(respuesta == -1){
		//perror("setuid");
		std::cout << "setuid ha devuelto " << respuesta << std::endl;
		std::cout << "ERROR: " << strerror(errno) << std::endl;
		return -1;	
	}
	return 1;
}
