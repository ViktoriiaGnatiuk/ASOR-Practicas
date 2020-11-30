#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
int main(int argc, char* argv[]) {
	if(argc == 1){
		std::cout << "Por favor introduzca una ruta de fichero o de directorio" << std:: endl;	
	}else{
		char *path = argv[1];

		long max_link = pathconf(path, _PC_LINK_MAX);
		if(max_link == -1){
			perror("_PC_LINK_MAX");
			return -1;
		}
		std::cout << "Número máximo de enlaces: " << max_link << std::endl;

		long max_path = pathconf(path, _PC_PATH_MAX);
		if(max_path == -1){
			perror("_PC_PATH_MAX");
			return -1;
		}
		std::cout << "Longitud máxima de la ruta relativa: " << max_path << std::endl;

		long max_file = pathconf(path, _PC_NAME_MAX);
		if(max_file == -1){
			perror("_PC_NAME_MAX");
			return -1;
		}
		std::cout << "_PC_NAME_MAX: " << max_file << std::endl;
	}
	return 0;
}
