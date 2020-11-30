#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
int main(int argc, char* argv[]) {
	long max_args = sysconf(_SC_ARG_MAX);
	if(max_args == -1){
		perror("_SC_ARG_MAX");
		return -1;
	}
	std::cout << "Longitud máxima de argumentos: " << max_args << std::endl;

	long max_child = sysconf(_SC_CHILD_MAX);
	if(max_child == -1){
		perror("_SC_CHILD_MAX");
		return -1;
	}
	std::cout << "Número máximo de procesos simultáneos: " << max_child << std::endl;

	long max_files = sysconf(_SC_OPEN_MAX);
	if(max_files == -1){
		perror("_SC_OPEN_MAX");
		return -1;
	}
	std::cout << "Número máximo de ficheros abiertos por proceso: " << max_files << std::endl;

	return 0;
}
