#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
int main() {
	for(int i=1; i <  134; i++) {
		std::cout <<i<< " - " << strerror(i) << std::endl;	
	}
	return -1;
}
