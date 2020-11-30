#include <unistd.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <string>

int main(int argc, char* argv[]) {
	struct utsname buf;
	int answer = uname(&buf);
	if(answer == -1 ){
		perror("uname");
		return -1;		
	}
	//struct utsname {
	  //char sysname[];    /* Operating system name (e.g., "Linux") */
	  //char nodename[];   /* Name within "some implementation-defined network" */
	  //char release[];    /* Operating system release (e.g., "2.6.28") */
	  //char version[];    /* Operating system version */
	  //char machine[];    /* Hardware identifier */
	//};
	if(argc == 1){
		std::cout << buf.sysname << std::endl;
	}else{
		for(int i=0; i < argc; i++){
			if(strcmp(argv[i], "-a") == 0){
				std::cout << buf.sysname << " " << buf.nodename << " " << buf.release << " " << buf.version << " " << buf.machine << std::endl;
			}else
			if(strcmp(argv[i], "-s") == 0){
				std::cout << buf.sysname << std::endl;
			}else
			if(strcmp(argv[i], "-n") == 0){
				std::cout << buf.nodename << std::endl;
			}else
			if(strcmp(argv[i], "-r") == 0){
				std::cout << buf.release << std::endl;
			}else
			if(strcmp(argv[i], "-v") == 0){
				std::cout << buf.version << std::endl;
			}else
			if(strcmp(argv[i], "-m") == 0){
				std::cout << buf.machine << std::endl;
			}else
			if(strcmp(argv[i], "-p") == 0){
				std::cout << buf.machine << std::endl;
			}else
			if(strcmp(argv[i], "-i") == 0){
				std::cout << buf.machine << std::endl;
			}else
			if(strcmp(argv[i], "-o") == 0){
				std::cout << buf.sysname << std::endl;
			}
				
		}
	}
	return 0;
}
