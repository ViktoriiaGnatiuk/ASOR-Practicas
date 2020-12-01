#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <time.h>
int main() {
	time_t t = time(NULL);
	if(t == -1){
		perror("time");
		return -1;	
	}
	std::cout << t << std::endl;
	return 1;
}
